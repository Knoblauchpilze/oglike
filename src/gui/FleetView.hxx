#ifndef FLEETVIEW_HXX
#define FLEETVIEW_HXX

#include "FleetView.h"

namespace ogame {
  namespace gui {

    inline
    void FleetView::populateActionData(const std::string& origin, ElementDescriptionPanel& action) const {
      // We need to extract the type of ship from the input origin name.
      try {
        const core::Ship::Type shipType = computeShipFromOriginNode(origin);

        // Assign the corresponding image into the panel.
        const std::string image = getPictureNameFromShip(shipType);
        action.setImagePath(image);

        // Now retrieve information about this ship using the active planet.
        const player::GeneralDataModel& model = getDataModel();
        const core::Planet& planet = model.getActivePlanet();
        const core::Ship& ship = planet.getShipData(shipType);

        // And update the corresponding element description.
        action.populateInformationFromElement(ship, planet);
      }
      catch (const player::DataModelException& e) {
        std::cerr << "[FLEET] Could not populate action data in " << getName() << " from origin " << origin << ":" << std::endl << e.what() << std::endl;
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[FLEET] Could not populate action data in " << getName() << " from origin " << origin << ":" << std::endl << e.what() << std::endl;
      }
      catch (const GuiException& e) {
        std::cerr << "[FLEET] Could not populate action data in " << getName() << " from origin " << origin << ":" << std::endl << e.what() << std::endl;
      }
    }

    inline
    const std::string FleetView::getShipCountFromType(const core::Ship::Type& type, const core::Planet& planet) const noexcept {
      return std::to_string(planet.getShipCount(type));
    }

    inline
    const core::Ship::Type FleetView::computeShipFromOriginNode(const std::string& origin) const noexcept {
      if (origin == "light_fighter") {
        return core::Ship::Type::LightFighter;
      }
      else if (origin == "heavy_fighter") {
        return core::Ship::Type::HeavyFighter;
      }
      else if (origin == "cruiser") {
        return core::Ship::Type::Cruiser;
      }
      else if (origin == "battleship") {
        return core::Ship::Type::Battleship;
      }
      else if (origin == "battlecruiser") {
        return core::Ship::Type::Battlecruiser;
      }
      else if (origin == "bomber") {
        return core::Ship::Type::Bomber;
      }
      else if (origin == "destroyer") {
        return core::Ship::Type::Destroyer;
      }
      else if (origin == "deathstar") {
        return core::Ship::Type::Deathstar;
      }
      else if (origin == "small_cargo") {
        return core::Ship::Type::SmallCargo;
      }
      else if (origin == "large_cargo") {
        return core::Ship::Type::LargeCargo;
      }
      else if (origin == "colony_ship") {
        return core::Ship::Type::ColonyShip;
      }
      else if (origin == "recycler") {
        return core::Ship::Type::Recycler;
      }
      else if (origin == "espionage_probe") {
        return core::Ship::Type::EspionageProbe;
      }
      else {
        return core::Ship::Type::SolarSatellite;
      }
    }

    inline
    const std::string FleetView::getPictureNameFromShip(const core::Ship::Type& type) const noexcept {
      const std::string path("data/img/");
      std::string image;
      const std::string extension(".bmp");

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

#endif // FLEETVIEW_HXX
