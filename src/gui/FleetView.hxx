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

    inline
    const std::string FleetView::getPictureNameFromShip(const core::Ship::Type& type, const bool reduced) const noexcept {
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

    inline
    LabelledPictureShPtr FleetView::createLabelledPictureContainer(const std::string& name,
                                                                   const std::string& picture,
                                                                   const std::string& text)
    {
      return ComponentFactory::createLabelledPicturePanel(
        name,
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/upcfb.ttf"),
          219, 140, 40, SDL_ALPHA_OPAQUE
        ),
        picture,
        text,
        LabelledPicture::Alignment::Above,
        view::EventListener::Interaction::NoInteraction
      );
    }

  }
}

#endif // FLEETVIEW_HXX
