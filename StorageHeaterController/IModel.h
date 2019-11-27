#ifndef __IMODEL_H__
#define __IMODEL_H__

#include "IModelListener.h"
#include <vector>

namespace StorageHeaterControl
{
    /** \brief Interface class for the Model class(es)
     *
     */
    class IModel
    {
        public:
            IModel(){}
            virtual ~IModel(){}

            /**
             * \brief   Sets the schedule for the IModel to use.
             *
             * \param   A reference to a const vector of bools containing the required schedule.
             */
            virtual void setSchedule( const std::vector<bool> &schedule ) = 0;

            /**
             * \brief   Gets the current state of the IModel.
             *
             * \return   A bool indicating whether the schedule is currently on or off.
             */
            virtual bool getCurrentState() = 0;

            /**
             * \brief   Adds a listener to the IModel.
             *
             * The IModel class should call the \ref IModelListener::modelChanged() member function
             * of the IModelListener whenever it's state changes.
             *
             * \param   A pointer to the IModelListener instance.
             */
            virtual void addListener( IModelListener *listener ) = 0;
    };
}
#endif // __IMODEL_H__
