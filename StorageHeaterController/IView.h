#ifndef __IVIEW_H__
#define __IVIEW_H__

#include "IViewListener.h"
#include <iostream>

/**
 * Interface class for the View class(es)
 *
 */

class IView
{
    public:
        IView(){}
        virtual ~IView(){}

        virtual void updateView( bool bState ) = 0;
        virtual void fireViewChanged() = 0;
        virtual void addListener( IViewListener* listener ) = 0;
};

#endif // __IVIEW_H__
