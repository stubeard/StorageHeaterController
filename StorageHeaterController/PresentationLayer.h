#ifndef __PRESENTATION_LAYER_H__
#define __PRESENTATION_LAYER_H__

#include "IModel.h"
#include "IView.h"

#include "IModelListener.h"
#include "IViewListener.h"

class PresentationLayer : public IModelListener, public IViewListener
{
    public:
        PresentationLayer( IModel& model, IView& view );
        virtual ~PresentationLayer();
        virtual void viewChanged();
        virtual void modelChanged();

    private:
        IModel& m_Model;
        IView&  m_View;
};

#endif // __PRESENTATION_LAYER_H__
