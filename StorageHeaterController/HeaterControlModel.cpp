#include "HeaterControlModel.h"

namespace StorageHeaterControl
{
    HeaterControlModel::HeaterControlModel( const int_fast64_t &interval )
    : m_listeners{}, m_currentState{ false }, m_interval{ interval }
    {

    }

    HeaterControlModel::~HeaterControlModel()
    {

    }

    void HeaterControlModel::setSchedule( std::vector<bool> &schedule )
    {

    }

    void HeaterControlModel::fireModelChanged()
    {

    }

    bool HeaterControlModel::getCurrentState()
    {
        return true;
    }

    void HeaterControlModel::addListener( IModelListener* listener )
    {
        if( listener )
        {
            m_listeners.push_back( std::move( listener ) );
        }
    }
}
