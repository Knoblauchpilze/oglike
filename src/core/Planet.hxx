#ifndef PLANET_HXX
#define PLANET_HXX

#include "Planet.h"

namespace ogame {
  namespace core {

    inline
    const std::string& Planet::getName() const noexcept {
      return m_name;
    }

    inline
    const bool Planet::hasMoon() const noexcept {
      return true;
    }

    inline
    const bool Planet::hasWreckfield() const noexcept {
      return true;
    }

  }
}

#endif // PLANET_HXX
