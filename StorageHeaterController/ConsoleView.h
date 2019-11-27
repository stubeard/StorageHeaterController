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

            virtual void updateView( bool state );
            virtual void addListener( IViewListener *listener );
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
