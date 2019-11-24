#ifndef __HEATER_CONTROL_MODEL_H__
#define __HEATER_CONTROL_MODEL_H__

#include "IModel.h"
#include <vector>
#include <string>

class HeaterControlModel : public IModel
{
    public:
        HeaterControlModel();
        virtual ~HeaterControlModel();
        virtual void setSchedule( std::string strSchedule );
        virtual void fireModelChanged();
        virtual bool getCurrentState();
        virtual void addListener( IModelListener* listener );

    private:
        std::vector<IModelListener*> m_pListeners;
        std::string m_strSchedule;
        bool m_bCurrentState;
};

#endif // __HEATER_CONTROL_MODEL_H__
