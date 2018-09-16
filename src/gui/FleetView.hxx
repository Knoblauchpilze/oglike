#ifndef FLEETVIEW_HXX
#define FLEETVIEW_HXX

#include "FleetView.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    inline
    void FleetView::onActionTriggered(const player::GeneralDataModel& model, const player::Action& action) {
      // Process this action.
      try {
        const core::Planet& planet = model.getActivePlanet();
        populateWithPlanetData(planet);
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[DEFENSE] Caught exception while setting up view " << getName() << ":" << std::endl << e.what() << std::endl;
      }
      catch (const player::DataModelException& e) {
        std::cerr << "[DEFENSE] Caught exception while setting up view " << getName() << ":" << std::endl << e.what() << std::endl;
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

  }
}

#endif // FLEETVIEW_HXX
