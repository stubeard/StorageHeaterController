#ifndef __IVIEW_LISTENER_H__
#define __IVIEW_LISTENER_H__

#include <iostream>

/** \brief Interface class for callbacks to the Presentation Layer class
 *
 */

namespace StorageHeaterControl
{
    class IViewListener
    {
        public:
            IViewListener(){}
            virtual ~IViewListener(){}
            virtual void viewChanged() = 0;
    };
}
#endif // __IVIEW_LISTENER_H__
