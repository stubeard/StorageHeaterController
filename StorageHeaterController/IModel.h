#ifndef __IMODEL_H__
#define __IMODEL_H__

#include "IModelListener.h"
#include <vector>

/** \brief Interface class for the Model class(es)
 *
 */

namespace StorageHeaterControl
{
    class IModel
    {
        public:
            IModel(){}
            virtual ~IModel(){}

            virtual void setSchedule( const std::vector<bool> &schedule ) = 0;
            virtual bool getCurrentState() = 0;
            virtual void addListener( IModelListener *listener ) = 0;
    };
}
#endif // __IMODEL_H__
