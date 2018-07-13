#ifndef PLANET_HXX
#define PLANET_HXX

#include "Planet.h"
#include "PlanetException.h"

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
      return m_account != nullptr;
    }

    inline
    const bool Planet::hasMoon() const noexcept {
      return false;
    }

    inline
    const bool Planet::hasWreckfield() const noexcept {
      return false;
    }

    inline
    const std::string Planet::generateRandomName(const unsigned& length) const noexcept {
      std::string name;
      name.resize(length);
      unsigned index = 0u;
      while (index < length) {
        name[index] = 'a' + std::rand() % ('z' - 'a');
        ++index;
      }
      return name;
    }

    inline
    const float Planet::getResourceQuantity(const std::string& name) const {
      return 456.0f;
    }

    inline
    const System& Planet::getSystem() const {
      if (m_parent == nullptr) {
        throw PlanetException(std::string("Could not retrieve system of planet ") + std::to_string(m_index) + " no associated system");
      }
      return *m_parent;
    }

  }
}

#endif // PLANET_HXX
