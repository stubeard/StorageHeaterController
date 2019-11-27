#ifndef __PRESENTATION_LAYER_H__
#define __PRESENTATION_LAYER_H__

#include "IModel.h"
#include "IView.h"

#include "IModelListener.h"
#include "IViewListener.h"

namespace StorageHeaterControl
{
    /** \brief Class for communicating between View and Model
     *
     */

    class PresentationLayer : public IModelListener, public IViewListener
    {
        public:
            PresentationLayer( IModel &model, IView &view );
            virtual ~PresentationLayer();

            /**
             * \brief   Called when the IView's state has changed.
             */
            virtual void viewChanged();

            /**
             * \brief   Called when the IModel's state has changed.
             */
            virtual void modelChanged();

        private:
            IModel &m_model;
            IView  &m_view;
    };
}
#endif // __PRESENTATION_LAYER_H__
