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
    std::string Ship::getNameFromType(const Type& type) noexcept {
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

    inline
    Ship::Type Ship::getTypeFromName(const std::string& name) noexcept {
      if (name =="light_fighter") {
        return Type::LightFighter;
      }
      else if (name =="heavy_fighter") {
        return Type::HeavyFighter;
      }
      else if (name =="cruiser") {
        return Type::Cruiser;
      }
      else if (name =="battleship") {
        return Type::Battleship;
      }
      else if (name =="battlecruiser") {
        return Type::Battlecruiser;
      }
      else if (name =="bomber") {
        return Type::Bomber;
      }
      else if (name =="destroyer") {
        return Type::Destroyer;
      }
      else if (name =="deathstar") {
        return Type::Deathstar;
      }
      else if (name =="small_cargo") {
        return Type::SmallCargo;
      }
      else if (name =="large_cargo") {
        return Type::LargeCargo;
      }
      else if (name =="colony_ship") {
        return Type::ColonyShip;
      }
      else if (name =="recycler") {
        return Type::Recycler;
      }
      else if (name =="espionage_probe") {
        return Type::EspionageProbe;
      }
      else {
        return Type::SolarSatellite;
      }
    }

  }
}

#endif // SHIP_HXX
