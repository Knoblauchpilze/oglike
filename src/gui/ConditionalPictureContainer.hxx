#ifndef CONDITIONALPICTURECONTAINER_HXX
#define CONDITIONALPICTURECONTAINER_HXX

#include "ConditionalPictureContainer.h"

namespace ogame {
  namespace gui {

    inline
    const bool ConditionalPictureContainer::getStatus() {
      lock();
      const bool status = m_active;
      unlock();
      return status;
    }

    inline
    void ConditionalPictureContainer::setActive(const bool active) {
      lock();
      m_active = active;
      makeDeepDirty();
      unlock();
    }

    inline
    void ConditionalPictureContainer::clearContentPrivate(SDL_Surface* render) {
      // Nothing to do here.
    }

  }
}

#endif // CONDITIONALPICTURECONTAINER_HXX
