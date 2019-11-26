#include "ConsoleView.h"

namespace StorageHeaterControl
{
    ConsoleView::ConsoleView(): m_schedule{}, m_listeners{}
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

    void ConsoleView::addListener( IViewListener *listener )
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
}
