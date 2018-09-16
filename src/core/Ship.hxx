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

    inline
    std::string Ship::getPictureNameFromShip(const core::Ship::Type& type, const bool reduced) noexcept {
      const std::string path("data/img/");
      std::string image;
      const std::string extension(reduced ? "_small.bmp" : ".bmp");

      switch (type) {
        case core::Ship::Type::LightFighter:
          image = std::string("light_fighter");
          break;
        case core::Ship::Type::HeavyFighter:
          image = std::string("heavy_fighter");
          break;
        case core::Ship::Type::Cruiser:
          image = std::string("cruiser");
          break;
        case core::Ship::Type::Battleship:
          image = std::string("battleship");
          break;
        case core::Ship::Type::Battlecruiser:
          image = std::string("battlecruiser");
          break;
        case core::Ship::Type::Bomber:
          image = std::string("bomber");
          break;
        case core::Ship::Type::Destroyer:
          image = std::string("destroyer");
          break;
        case core::Ship::Type::Deathstar:
          image = std::string("deathstar");
          break;
        case core::Ship::Type::SmallCargo:
          image = std::string("small_cargo_ship");
          break;
        case core::Ship::Type::LargeCargo:
          image = std::string("large_cargo_ship");
          break;
        case core::Ship::Type::ColonyShip:
          image = std::string("colony_ship");
          break;
        case core::Ship::Type::Recycler:
          image = std::string("recycler");
          break;
        case core::Ship::Type::EspionageProbe:
          image = std::string("espionage_probe");
          break;
        case core::Ship::Type::SolarSatellite:
        default:
          image = std::string("solar_satellite");
          break;
      }

      return path + image + extension;
    }

  }
}

#endif // SHIP_HXX
