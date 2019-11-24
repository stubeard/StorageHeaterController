#include "PresentationLayer.h"

PresentationLayer::PresentationLayer( IModel& model, IView& view ): m_Model{ model }, m_View{ view }
{
    m_Model.addListener( this );
    m_View.addListener( this );
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
