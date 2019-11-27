#ifndef __CONSOLE_VIEW_H__
#define __CONSOLE_VIEW_H__

#include "IView.h"
#include <vector>
#include <thread>
#include <mutex>

namespace StorageHeaterControl
{
    /** \brief Concrete implementation of the IView interface using the console.
     *
     */
    class ConsoleView : public IView
    {
        public:
            ConsoleView();
            virtual ~ConsoleView();

            /**
             * \brief   Updates the IView's output with the current state.
             *
             * \param   A bool indicating the required state.
             */
            virtual void updateView( bool state );

            /**
             * \brief   Adds a listener to the ConsoleView.
             *
             * The ConsoleView class calls the \ref IViewListener::viewChanged() member function
             * of the IViewListener whenever it's state changes.
             *
             * \param   A pointer to the IViewListener instance.
             */
            virtual void addListener( IViewListener *listener );

            /**
             * \brief   Returns the schedule input into the ConsoleView via std::cin.
             *
             * \return   A vector of bools containing the required schedule.
             */
            virtual std::vector<bool> getSchedule();

        private:
            std::vector<bool> m_schedule;
            std::vector<IViewListener*> m_listeners;
            std::thread m_thread;
            bool m_running;
            std::mutex m_lock;

            void fireViewChanged();
            void timedLoop();
            void waitForInput();
            bool validateInput( const std::string &input );
            void decodeInput( const std::string &input );
    };
}
#endif // __CONSOLE_VIEW_H__
