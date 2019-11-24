#ifndef __CONSOLE_VIEW_H__
#define __CONSOLE_VIEW_H__

#include "IView.h"
#include <vector>


class ConsoleView : public IView
{
    public:
        ConsoleView();
        virtual ~ConsoleView();

        virtual void updateView( bool bState );
        virtual void fireViewChanged();
        virtual void addListener( IViewListener* listener );

    private:
        std::vector<IViewListener*> m_pListeners;
};

#endif // __CONSOLE_VIEW_H__
