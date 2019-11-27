#ifndef __IVIEW_H__
#define __IVIEW_H__

#include "IViewListener.h"
#include <vector>
#include <iostream>

namespace StorageHeaterControl
{
    /** \brief Interface class for the View class(es)
     *
     */
    class IView
    {
        public:
            IView(){}
            virtual ~IView(){}

            /**
             * \brief   Updates the IView's output with the current state.
             *
             * \param   A bool indicating the required state.
             */
            virtual void updateView( bool state ) = 0;

            /**
             * \brief   Adds a listener to the IView.
             *
             * The IView class should call the viewChanged() member function
             * of the IViewListener whenever it's state changes.
             *
             * \param   A pointer to the IViewListener instance.
             */
            virtual void addListener( IViewListener *listener ) = 0;

            /**
             * \brief   Returns the schedule input into the IView.
             *
             * \return   A vector of bools containing the required schedule.
             */
            virtual std::vector<bool> getSchedule() = 0;
    };
}
#endif // __IVIEW_H__
