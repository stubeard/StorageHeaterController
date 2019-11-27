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

            /**
             * \brief   Sets the schedule for the HeaterControlModel to use.
             *
             * \param   A reference to a const vector of bools containing the required schedule.
             */
            virtual void setSchedule( const std::vector<bool> &schedule );

            /**
             * \brief   Gets the current state of the HeaterControlModel.
             *
             * \return   A bool indicating whether the schedule is currently on or off.
             */
            virtual bool getCurrentState();

            /**
             * \brief   Adds a listener to the HeaterControlModel.
             *
             * The HeaterControlModel class calls the \ref IModelListener::modelChanged() member function
             * of the IModelListener whenever it's state changes.
             *
             * \param   A pointer to the IModelListener instance.
             */
            virtual void addListener( IModelListener *listener );

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
            void setCurrentState( bool state );
            void timedLoop();
    };

}
#endif // __HEATER_CONTROL_MODEL_H__
