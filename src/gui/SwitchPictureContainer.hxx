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

  }
}

#endif // SWITCHPICTURECONTAINER_HXX
