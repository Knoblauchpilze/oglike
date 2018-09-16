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
    std::string Defense::getPictureNameFromDefense(const core::Defense::Type& type, const bool reduced) noexcept {
      const std::string path("data/img/");
      std::string image;
      const std::string extension(reduced ? "_small.bmp" : ".bmp");

      switch (type) {
        case core::Defense::Type::MissileLauncher:
          image = std::string("missile_launcher");
          break;
        case core::Defense::Type::LightLaser:
          image = std::string("light_laser");
          break;
        case core::Defense::Type::HeavyLaser:
          image = std::string("heavy_laser");
          break;
        case core::Defense::Type::GaussCannon:
          image = std::string("gauss_cannon");
          break;
        case core::Defense::Type::IonCannon:
          image = std::string("ion_cannon");
          break;
        case core::Defense::Type::PlasmaTurret:
          image = std::string("plasma_turret");
          break;
        case core::Defense::Type::SmallShieldDome:
          image = std::string("small_shield_dome");
          break;
        case core::Defense::Type::LargeShieldDome:
          image = std::string("large_shield_dome");
          break;
        case core::Defense::Type::AntiballisticMissile:
          image = std::string("antiballistic_missile");
          break;
        case core::Defense::Type::InterplanetaryMissile:
        default:
          image = std::string("interplanetary_missile");
          break;
      }

      return path + image + extension;
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
