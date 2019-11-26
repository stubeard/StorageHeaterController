#ifndef __CONSOLE_VIEW_H__
#define __CONSOLE_VIEW_H__

#include "IView.h"
#include <vector>
#include <thread>

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
            virtual std::vector<bool> &getSchedule();

        private:
            std::vector<bool> m_schedule;
            std::vector<IViewListener*> m_listeners;

            void fireViewChanged();
    };
}
#endif // __CONSOLE_VIEW_H__
