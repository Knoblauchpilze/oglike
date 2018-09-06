#ifndef FLEET_HXX
#define FLEET_HXX

#include "Fleet.h"
#include "FleetException.h"

namespace ogame {
  namespace core {

    inline
    const std::string& Fleet::getName() const noexcept {
      return m_name;
    }

    inline
    const Planet& Fleet::getOrigin() const {
      if (m_originPlanet == nullptr) {
        throw FleetException(std::string("Could not retrieve null origin planet for fleet \"") + getName() + "\"");
      }
      return *m_originPlanet;
    }

    inline
    const Planet& Fleet::getTarget() const {
      if (m_targetPlanet == nullptr) {
        throw FleetException(std::string("Could not retrieve null target planet for fleet \"") + getName() + "\"");
      }
      return *m_targetPlanet;
    }

  }
}

#endif // FLEET_HXX
