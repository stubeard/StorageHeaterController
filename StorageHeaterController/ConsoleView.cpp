#include "ConsoleView.h"
#include "Defines.h"

namespace StorageHeaterControl
{
    ConsoleView::ConsoleView(): m_schedule{}, m_listeners{}, m_thread{ ConsoleView::timedLoop, this }
    {
        m_thread.detach();
        std::cout << "Please enter a schedule for the next " << ( StorageHeaterControl::PERIODS_IN_SCHEDULE / 2 ) << " hours." << std::endl;
        std::cout << "The schedule should contain " << StorageHeaterControl::PERIODS_IN_SCHEDULE << " digits (one for each 30 minute period in the following " << ( StorageHeaterControl::PERIODS_IN_SCHEDULE / 2 ) << " hours)," << std::endl;
        std::cout << "and should consist of '1's (ON) and '0's (OFF) only in the following pattern:" << std::endl;
        std::cout << StorageHeaterControl::TEMPLATE << std::endl;
    }

    ConsoleView::~ConsoleView()
    {
        m_running = false;
        if( m_thread.joinable() )
        {
            m_thread.join();
        }
    }

    void ConsoleView::updateView( bool state )
    {
        std::cout << ( state ? "ON" : "OFF" ) << std::endl;
    }

    void ConsoleView::fireViewChanged()
    {
        for( auto listener : m_listeners )
        {
            listener->viewChanged();
        }
    }

    void ConsoleView::addListener( IViewListener* listener )
    {
        if( listener )
        {
            m_listeners.push_back( std::move( listener ) );
        }
    }

    std::vector<bool>& ConsoleView::getSchedule()
    {
        return m_schedule;
    }

    void ConsoleView::timedLoop()
    {
        while( m_running )
        {
            std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
            waitForInput();
        }
    }

    void ConsoleView::waitForInput()
    {
        std::string input;
        std::getline( std::cin, input );

        if( ! input.empty() )
        {
            if( validateInput( input ) )
            {
                decodeInput( input );
                fireViewChanged();
            }
        }
    }

    bool ConsoleView::validateInput( const std::string& input )
    {
        bool valid{ true };

        if( input.size() == StorageHeaterControl::PERIODS_IN_SCHEDULE )
        {
            for( size_t i = 0 ;
                     i < input.size() ;
                  ++ i )
            {
                //only 0 and 1 are acceptable;
                if(   ( input[ i ] != '0' ) &&
                      ( input[ i ] != '1' )   )
                {
                    valid = false;
                    break;
                }
            }

            if( ! valid )
            {
                std::cout << "The schedule can only contain 0s or 1s. Please try again." << std::endl;
            }
        }
        else
        {
            std::cout << "The schedule must be 48 characters long. Please try again." << std::endl;
            valid = false;
        }
        return valid;
    }

    void ConsoleView::decodeInput( const std::string& input )
    {
        m_schedule.clear();

        for( size_t i = 0 ;
                    i < input.size() ;
                 ++ i )
        {
            m_schedule.push_back( input[ i ] != '0' );
        }
    }
}
