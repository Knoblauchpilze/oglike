#ifndef EVENTLISTENER_HXX
#define EVENTLISTENER_HXX

#include "EventListener.h"

namespace ogame {
  namespace view {

    inline
    const EventListener::Interaction::Mask& EventListener::getInteractionMask() const noexcept {
      return m_mask;
    }

    inline
    bool EventListener::isRelevant(const Interaction::Mask& event) const noexcept {
      return m_mask & event;
    }

  }
}

#endif // EVENTLISTENER_HXX
