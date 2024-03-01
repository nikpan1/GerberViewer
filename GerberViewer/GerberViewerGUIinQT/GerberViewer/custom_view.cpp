#include "custom_view.h"



void Custom_View::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(AnchorUnderMouse);
    setDragMode(ScrollHandDrag);
    double scalefactor = 1.5;
    if(event->delta() > 0)
    {
        scale(scalefactor, scalefactor);
    }
    else
    {
        scale(1/scalefactor,1/scalefactor);
    }
}




