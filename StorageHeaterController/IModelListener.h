#ifndef __IMODEL_LISTENER_H__
#define __IMODEL_LISTENER_H__

#include <iostream>

namespace StorageHeaterControl
{
    /** \brief Interface class for callbacks to the Presentation Layer class
     * from an instance of IModel
     */
    class IModelListener
    {
        public:
            IModelListener(){}
            virtual ~IModelListener(){}

            /**
             * \brief   Should be called when the IModel's state has changed.
             */
            virtual void modelChanged() = 0;
    };
}
#endif // __IMODELLISTENER_H__
