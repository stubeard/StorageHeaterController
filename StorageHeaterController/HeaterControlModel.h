#ifndef __HEATER_CONTROL_MODEL_H__
#define __HEATER_CONTROL_MODEL_H__

#include "IModel.h"
#include "Delay.h"
#include "Defines.h"
#include <thread>
#include <deque>
#include <vector>
#include <mutex>

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
            virtual void setSchedule( const std::vector<bool> &schedule );
            virtual bool getCurrentState();
            virtual void addListener( IModelListener *listener );

            void setCurrentState( bool state );

        private:
            std::vector<IModelListener*> m_listeners;
            std::deque<bool> m_schedule;
            bool m_currentState;
            Delay<int_fast64_t> m_timer;
            const int_fast64_t m_interval;
            bool m_running;
            std::thread m_thread;
            std::mutex m_lock;

            void fireModelChanged();
            void processSchedule();
            void timedLoop();
    };

}
#endif // __HEATER_CONTROL_MODEL_H__
