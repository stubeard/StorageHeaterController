#include "PresentationLayer.h"

namespace StorageHeaterControl
{
    PresentationLayer::PresentationLayer( IModel& model, IView& view ): m_model{ model }, m_view{ view }
    {
        m_model.addListener( this );
        m_view.addListener( this );
    }

    PresentationLayer::~PresentationLayer()
    {

    }

    void PresentationLayer::viewChanged()
    {

    }

    void PresentationLayer::modelChanged()
    {

    }
}
