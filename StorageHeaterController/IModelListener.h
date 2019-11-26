#ifndef __IMODEL_LISTENER_H__
#define __IMODEL_LISTENER_H__

#include <iostream>

/** \brief Interface class for callbacks to the Presentation Layer class
 *
 */

namespace StorageHeaterControl
{
    class IModelListener
    {
        public:
            IModelListener(){}
            virtual ~IModelListener(){}
            virtual void modelChanged() = 0;
    };
}
#endif // __IMODELLISTENER_H__
