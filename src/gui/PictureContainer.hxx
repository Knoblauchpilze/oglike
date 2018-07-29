#ifndef PICTURECONTAINER_HXX
#define PICTURECONTAINER_HXX

#include "PictureContainer.h"

namespace ogame {
  namespace gui {

    inline
    void PictureContainer::setImagePath(const std::string& path) {
      lock();
      m_file = path;
      loadPicture();
      makeDeepDirty();
      unlock();
    }

    inline
    void PictureContainer::clear() {
      setImagePath(std::string(""));
    }

    inline
    void PictureContainer::clearContentPrivate(SDL_Surface* render) {
      // Nothing to do here.
    }

  }
}

#endif // PICTURECONTAINER_HXX
