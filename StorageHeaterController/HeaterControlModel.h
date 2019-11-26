#ifndef __HEATER_CONTROL_MODEL_H__
#define __HEATER_CONTROL_MODEL_H__

#include "IModel.h"
#include "Defines.h"
#include <thread>
#include <deque>
#include <vector>

namespace StorageHeaterControl
{
    /** \brief Concrete implementation of the IModel interface defining a Storage Heater Schedule
     *
     */
    class HeaterControlModel : public IModel
    {
        public:
            HeaterControlModel( const int_fast64_t &interval = StorageHeaterControl::SCHEDULE_UPDATE_TIME_IN_US );
            virtual ~HeaterControlModel();
            virtual void setSchedule( std::vector<bool> &schedule );
            virtual bool getCurrentState();
            virtual void addListener( IModelListener *listener );

        private:
            std::vector<IModelListener*> m_listeners;
            std::deque<bool> m_schedule;
            bool m_currentState;
            const int_fast64_t m_interval;

            void fireModelChanged();
    };
}
#endif // __HEATER_CONTROL_MODEL_H__
