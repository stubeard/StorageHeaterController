#include "ModelTest.h"
#include "HeaterControlModel.h"
#include <algorithm>
#include <chrono>

namespace StorageHeaterControl
{
    namespace Test
    {
        ModelTest::ModelTest( IModel &model ): m_model{ model }, m_test{}, m_result{}
        {
            m_model.addListener( this );

            encodeTestString( "001011001011010101010100000101011010010100100010" );
            std::cout << "Input:  ";
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
                    std::cout << "Success!!";
                }
                else
                {
                    std::cout << "Failed!";
                }
                std::cout << std::endl;
            }
            else if( m_result.size() > m_test.size() )
            {
                std::cout << "Failed!";
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

int main()
{
    StorageHeaterControl::HeaterControlModel model{ std::chrono::duration_cast<std::chrono::microseconds>( std::chrono::milliseconds( 100 ) ).count() };
    StorageHeaterControl::Test::ModelTest modeltest{ model };

    while( true )
    {
        std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
    }
}

