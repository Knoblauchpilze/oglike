#ifndef SHIPSELECTIONPANEL_HXX
#define SHIPSELECTIONPANEL_HXX

#include "ShipSelectionPanel.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    inline
    BackgroundedLabelShPtr ShipSelectionPanel::createBackgroundedLabelContainer(const std::string& name,
                                                                                const std::string& picture)
    {
      return ComponentFactory::createBackgroundedLabelPanel(
        name,
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/upcfb.ttf"),
          219, 140, 40, SDL_ALPHA_OPAQUE
        ),
        picture,
        std::to_string(0),
        SDL_Color{14, 57, 83, SDL_ALPHA_OPAQUE},
        BackgroundedLabel::Alignment::BottomRight
      );
    }

    inline
    const std::string ShipSelectionPanel::getPictureNameFromShip(const core::Ship::Type& type, const bool reduced) const noexcept {
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

#endif // SHIPSELECTIONPANEL_HXX
