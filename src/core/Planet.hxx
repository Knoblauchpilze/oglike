#ifndef PLANET_HXX
#define PLANET_HXX

#include "Planet.h"

namespace ogame {
  namespace core {

    inline
    bool Planet::operator==(const Planet& other) const noexcept {
      return other.m_index == m_index;
    }

    inline
    const std::string& Planet::getName() const noexcept {
      return m_name;
    }

    inline
    const bool Planet::isColonized() const noexcept {
      return /*false*/std::rand() % 2 == 0 ? false : true;
    }

    inline
    const bool Planet::hasMoon() const noexcept {
      return /*false*/std::rand() % 2 == 0 ? false : true;
    }

    inline
    const bool Planet::hasWreckfield() const noexcept {
      return /*false*/std::rand() % 2 == 0 ? false : true;
    }

  }
}

#endif // PLANET_HXX
