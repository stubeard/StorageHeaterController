#ifndef __IMODEL_H__
#define __IMODEL_H__

#include "IModelListener.h"
#include <string>

/**
 * Interface class for the Model class(es)
 *
 */


class IModel
{
    public:
        IModel(){}
        virtual ~IModel(){}

        virtual void setSchedule( std::string strSchedule ) = 0;
        virtual void fireModelChanged() = 0;
        virtual bool getCurrentState() = 0;
        virtual void addListener( IModelListener* listener ) = 0;
};

#endif // __IMODEL_H__
