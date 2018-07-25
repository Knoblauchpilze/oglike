#ifndef SHIP_HXX
#define SHIP_HXX

#include "Ship.h"

namespace ogame {
  namespace core {

    inline
    const Ship::Type& Ship::getType() const noexcept {
      return m_type;
    }

    inline
    const unsigned Ship::getCount() const noexcept {
      return 0u;
    }

    inline
    const std::string Ship::getNameFromType(const Type& type) const noexcept {
      std::string name = "Default ship name";

      switch (type) {
        case Type::HeavyFighter:
          name = "Heavy fighter";
          break;
        case Type::Cruiser:
          name = "Cruiser";
          break;
        case Type::Battleship:
          name = "Battleship";
          break;
        case Type::Battlecruiser:
          name = "Battlecruiser";
          break;
        case Type::Bomber:
          name = "Bomber";
          break;
        case Type::Destroyer:
          name = "Destroyer";
          break;
        case Type::Deathstar:
          name = "Deathstar";
          break;
        case Type::SmallCargo:
          name = "Small cargo ship";
          break;
        case Type::LargeCargo:
          name = "Large cargo ship";
          break;
        case Type::ColonyShip:
          name = "Colony ship";
          break;
        case Type::Recycler:
          name = "Recycler";
          break;
        case Type::EspionageProbe:
          name = "Espionage probe";
          break;
        case Type::SolarSatellite:
          name = "Solar satellite";
          break;
        case Type::LightFighter:
        default:
          name = "Light fighter";
          break;
      }

      return name;
    }

  }
}

#endif // SHIP_HXX
