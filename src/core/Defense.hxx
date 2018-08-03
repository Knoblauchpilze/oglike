#ifndef DEFENSE_HXX
#define DEFENSE_HXX

#include "Defense.h"

namespace ogame {
  namespace core {

    inline
    const Defense::Type& Defense::getType() const noexcept {
      return m_type;
    }

    inline
    const std::string Defense::getNameFromType(const Type& type) const noexcept {
      std::string name = "Default defense name";

      switch (type) {
        case Type::MissileLauncher:
          name = "Missile launcher";
          break;
        case Type::LightLaser:
          name = "Light laser";
          break;
        case Type::HeavyLaser:
          name = "Heavy laser";
          break;
        case Type::GaussCannon:
          name = "Gauss cannon";
          break;
        case Type::IonCannon:
          name = "Ion cannon";
          break;
        case Type::PlasmaTurret:
          name = "Plasma turret";
          break;
        case Type::SmallShieldDome:
          name = "Small shield dome";
          break;
        case Type::LargeShieldDome:
          name = "Large shield dome";
          break;
        case Type::AntiballisticMissile:
          name = "Antiballistic missile";
          break;
        case Type::InterplanetaryMissile:
        default:
          name = "Interplanetary missile";
          break;
      }

      return name;
    }

  }
}

#endif // DEFENSE_HXX
