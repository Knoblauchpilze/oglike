#ifndef SWITCHPICTURECONTAINER_HXX
#define SWITCHPICTURECONTAINER_HXX

#include "SwitchPictureContainer.h"

namespace ogame {
  namespace gui {

    inline
    void SwitchPictureContainer::updateStatus(bool status) {
      lock();
      m_status = status;
      makeDirty();
      unlock();
    }

    inline
    void SwitchPictureContainer::clearContentPrivate(SDL_Surface* render) {
      // Nothing to do here.
    }

    inline
    void SwitchPictureContainer::onMouseButtonReleasedEventPrivate(const SDL_MouseButtonEvent& mouseButtonEvent) {
      // React only if this container is active.
      if (m_status) {
        GraphicContainer::onMouseButtonReleasedEventPrivate(mouseButtonEvent);
      }
    }

  }
}

#endif // SWITCHPICTURECONTAINER_HXX
