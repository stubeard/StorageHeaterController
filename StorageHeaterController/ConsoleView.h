#ifndef __CONSOLE_VIEW_H__
#define __CONSOLE_VIEW_H__

#include "IView.h"


class ConsoleView : public IView
{
    public:
        ConsoleView();
        virtual ~ConsoleView();

        virtual void updateView( bool bState );
        virtual void fireViewChanged();
        virtual void addListener( ViewListener* listener );

    private:
        std::vector<ViewListener*> m_pListeners;
};

#endif // __CONSOLE_VIEW_H__
