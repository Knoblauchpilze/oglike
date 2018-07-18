


#ifndef SYSTEMCOORDINATES_HXX
#define SYSTEMCOORDINATES_HXX

#include "SystemCoordinates.h"

namespace ogame {
  namespace core {

    inline
    const unsigned& SystemCoordinates::getGalaxy() const noexcept {
      return m_galaxy;
    }

    inline
    const unsigned& SystemCoordinates::getSystem() const noexcept {
      return m_system;
    }

  }
}

#endif // SYSTEMCOORDINATES_HXX
