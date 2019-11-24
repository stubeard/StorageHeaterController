#ifndef __IVIEW_LISTENER_H__
#define __IVIEW_LISTENER_H__

#include <iostream>

/**
 * Interface class for callbacks to the Presentation Layer class
 *
 */

class IViewListener
{
    public:
        IViewListener(){}
        virtual ~IViewListener(){}
        virtual void modelChanged() = 0;
};

#endif // __IVIEW_LISTENER_H__
