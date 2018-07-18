#ifndef GRAPHIC_CONTAINER_LISTENER_H
#define GRAPHIC_CONTAINER_LISTENER_H

#include <memory>
#include "EventListener.h"

namespace ogame {
  namespace view {

    class GraphicContainerListener
    {
      public:

        GraphicContainerListener();

        virtual ~GraphicContainerListener();

        virtual void onInteractionPerformed(const std::string& origin, const view::EventListener::Interaction::Mask& mask) = 0;

      private:

    };

    using GraphicContainerListenerShPtr = std::shared_ptr<GraphicContainerListener>;
  }
}

#endif // GRAPHIC_CONTAINER_LISTENER_H
