#include "ConsoleView.h"

ConsoleView::ConsoleView(): m_pListeners{}
{

}

ConsoleView::~ConsoleView()
{

}

void ConsoleView::updateView( bool bState )
{

}

void ConsoleView::fireViewChanged()
{

}

void ConsoleView::addListener( IViewListener* listener )
{
    if( listener )
    {
        m_pListeners.push_back( std::move( listener ) );
    }
}
