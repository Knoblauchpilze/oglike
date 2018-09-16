#ifndef SHIPYARDVIEW_HXX
#define SHIPYARDVIEW_HXX

#include "ShipyardView.h"

namespace ogame {
  namespace gui {

    inline
    void ShipyardView::populateActionData(const std::string& origin, ElementDescriptionPanel& action) const {
      // We need to extract the type of ship from the input origin name.
      try {
        const core::Ship::Type shipType = computeShipFromOriginNode(origin);

        // Assign the corresponding image into the panel.
        const std::string image = core::Ship::getPictureNameFromShip(shipType, false);
        action.setImagePath(image);

        // Now retrieve information about this ship using the active planet.
        const player::GeneralDataModel& model = getDataModel();
        const core::Account& account = model.getActiveAccount();
        const core::Planet& planet = model.getActivePlanet();
        const core::Ship& ship = planet.getShipData(shipType);

        // And update the corresponding element description.
        action.populateInformationFromElement(ship, planet, account);
      }
      catch (const player::DataModelException& e) {
        std::cerr << "[SHIPYARD] Could not populate action data in " << getName() << " from origin " << origin << ":" << std::endl << e.what() << std::endl;
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[SHIPYARD] Could not populate action data in " << getName() << " from origin " << origin << ":" << std::endl << e.what() << std::endl;
      }
      catch (const GuiException& e) {
        std::cerr << "[SHIPYARD] Could not populate action data in " << getName() << " from origin " << origin << ":" << std::endl << e.what() << std::endl;
      }
    }

    inline
    const std::string ShipyardView::getShipCountFromType(const core::Ship::Type& type, const core::Planet& planet) const noexcept {
      return std::to_string(planet.getShipCount(type));
    }

    inline
    const core::Ship::Type ShipyardView::computeShipFromOriginNode(const std::string& origin) const noexcept {
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

  }
}

#endif // SHIPYARDVIEW_HXX
