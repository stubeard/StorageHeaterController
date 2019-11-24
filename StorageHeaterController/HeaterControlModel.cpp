#include "HeaterControlModel.h"

HeaterControlModel::HeaterControlModel(): m_pListeners{}
{

}

HeaterControlModel::~HeaterControlModel()
{

}
void HeaterControlModel::setSchedule( std::string strSchedule )
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
        m_pListeners.push_back( std::move( listener ) );
    }
}
