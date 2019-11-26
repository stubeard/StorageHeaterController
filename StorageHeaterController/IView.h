#ifndef __IVIEW_H__
#define __IVIEW_H__

#include "IViewListener.h"
#include <vector>
#include <iostream>

/** \brief Interface class for the View class(es)
 *
 */

namespace StorageHeaterControl
{
    class IView
    {
        public:
            IView(){}
            virtual ~IView(){}

            virtual void updateView( bool state ) = 0;
            virtual void addListener( IViewListener *listener ) = 0;
            virtual std::vector<bool> &getSchedule() = 0;
    };
}
#endif // __IVIEW_H__
