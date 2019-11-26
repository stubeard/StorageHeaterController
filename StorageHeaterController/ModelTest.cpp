#include "ModelTest.h"
#include "HeaterControlModel.h"
#include "Defines.h"
#include <algorithm>
#include <chrono>
#include <signal.h>

namespace StorageHeaterControl
{
    namespace Test
    {
        ModelTest::ModelTest( IModel &model ): m_finished{ false }, m_success{ false }, m_model{ model }, m_test{}
        {
            m_model.addListener( this );

            encodeTestString( "001011001011010101010100000101011010010100100010" );
            std::cout << "Input : ";
            for( size_t i = 0 ;
                        i < m_test.size() ;
                     ++ i )
            {
                std::cout << m_test[ i ];
            }
            std::cout << std::endl;

            m_result.clear();

            std::cout << "Output: ";
            m_model.setSchedule( m_test );
        }

        ModelTest::~ModelTest()
        {

        }

        void ModelTest::modelChanged()
        {
            bool state = m_model.getCurrentState();
            m_result.push_back( state );
            std::cout << state;

            if( m_result.size() == m_test.size() )
            {
                std::cout << std::endl;

                if( std::equal( m_test.begin(),
                                m_test.end(),
                                m_result.begin() ) )
                {
                    m_success = true;
                }
                else
                {
                    m_success = false;
                    m_finished = true;
                }
            }
            else if( m_result.size() > m_test.size() )
            {
                m_success  = false;
                m_finished = true;
            }
        }

        void ModelTest::encodeTestString( std::string test )
        {
            m_test.clear();

            for( size_t i = 0 ;
                        i < test.size() ;
                     ++ i )
            {
                m_test.push_back( test[ i ] != '0' );
            }
        }
    }
}

bool running = true;

static void signal_handler( int s )
{
    running = false;
}

int main()
{
    std::cout << "Storage Heater Model Test, Version [" << StorageHeaterControl::VERSION << "] Built on [" << __DATE__ << "] at [" __TIME__ << "]" << std::endl;

    signal( SIGINT, signal_handler );

    StorageHeaterControl::HeaterControlModel model{ std::chrono::duration_cast<std::chrono::microseconds>( std::chrono::milliseconds( 100 ) ).count() };
    StorageHeaterControl::Test::ModelTest modeltest{ model };

    while(   ( running ) &&
             ( ! modeltest.m_finished )   )
    {
        std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
        if( modeltest.m_success )
        {
            //wait a little longer to make sure no extra states are received
            std::this_thread::sleep_for( std::chrono::seconds( 3 ) );
            modeltest.m_finished = true;
        }
    }

    if( running ) //check we weren't interrupted
    {
        std::cout << ( modeltest.m_success ? "Passed" : "Failed" ) << std::endl;
    }
}

