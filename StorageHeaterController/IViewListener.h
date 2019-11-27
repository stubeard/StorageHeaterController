#ifndef __IVIEW_LISTENER_H__
#define __IVIEW_LISTENER_H__

#include <iostream>

namespace StorageHeaterControl
{
    /** \brief Interface class for callbacks to the Presentation Layer class
     * from an instance of IView
     */
    class IViewListener
    {
        public:
            IViewListener(){}
            virtual ~IViewListener(){}

            /**
             * \brief   Should be called when the IView's state has changed.
             */
            virtual void viewChanged() = 0;
    };
}
#endif // __IVIEW_LISTENER_H__
