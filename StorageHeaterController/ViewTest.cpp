#include "ViewTest.h"
#include "ConsoleView.h"
#include <vector>
#include <iostream>

namespace StorageHeaterControl
{
    namespace Test
    {
        ViewTest::ViewTest( IView &view ): m_view{ view }
        {
            m_view.addListener( this );
        }

        ViewTest::~ViewTest()
        {

        }

        void ViewTest::viewChanged()
        {
            std::vector<bool> schedule{ m_view.getSchedule() };

            std::cout << "size=" << schedule.size() << std::endl;
            for( size_t i = 0 ;
                      i < schedule.size() ;
                   ++ i )
            {
                std::cout << ( i + 1 ) << "=>" << std::boolalpha << schedule[ i ] << "=";
                m_view.updateView( schedule[ i ] );
            }
        }
    }
}

int main()
{
    StorageHeaterControl::ConsoleView view{};
    StorageHeaterControl::Test::ViewTest viewtest{ view };

    while( true )
    {
        std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
    }
}
