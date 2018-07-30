#ifndef UPGRADEACTIONCONTAINER_HXX
#define UPGRADEACTIONCONTAINER_HXX

#include "UpgradeActionContainer.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    inline
    LabelContainerShPtr UpgradeActionContainer::createLabel(const std::string& name,
                                                            const std::string& text,
                                                            const SDL_Color& textColor,
                                                            const LabelContainer::Alignment& alignment,
                                                            const SDL_Color& bgColor,
                                                            const bool transparent,
                                                            const int& policeSize) const
    {
      return ComponentFactory::createLabelPanel(
        name,
        text,
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/tahomabd.ttf"),
          textColor.r, textColor.g, textColor.b, textColor.unused,
          policeSize
        ),
        alignment,
        bgColor,
        transparent
      );
    }

    inline
    PhotoGalleryShPtr UpgradeActionContainer::createPhotoGallery(const std::string& name,
                                                                 const unsigned& picturesCount) const
    {
      return ComponentFactory::createPhotoGalleryPanel(
        name,
        picturesCount
      );
    }
    
    inline
    const std::string UpgradeActionContainer::computeDisplayTime(const float& seconds) const {
      // Compute values up to a year.
      const int uSeconds = static_cast<int>(seconds);
      const int years =   uSeconds / (60 * 60 * 24 * 7 * 52);
      const int weeks =   uSeconds / (60 * 60 * 24 * 7)         -     years * 52;
      const int days =    uSeconds / (60 * 60 * 24)             -    (years * 52 + weeks) * 7;
      const int hours =   uSeconds / (60 * 60)                  -   ((years * 52 + weeks) * 7 + days) * 24;
      const int minutes = uSeconds / (60)                       -  (((years * 52 + weeks) * 7 + days) * 24 + hours) * 60;
      const int realSec = uSeconds                              - ((((years * 52 + weeks) * 7 + days) * 24 + hours) * 60 + minutes) * 60;

      // Build the final string.
      std::string duration;
      if (std::abs(years) > 0) {
        duration += (std::to_string(years) + "y ");
      }
      if (std::abs(weeks) > 0) {
        duration += (std::to_string(weeks) + "w ");
      }
      if (std::abs(days) > 0) {
        duration += (std::to_string(days) + "d ");
      }
      if (std::abs(hours) > 0) {
        duration += (std::to_string(hours) + "h ");
      }
      if (std::abs(minutes) > 0) {
        duration += (std::to_string(minutes) + "m ");
      }
      if (std::abs(realSec) > 0) {
        duration += (std::to_string(realSec) + "s");
      }

      return duration;
    }

    inline
    const std::string UpgradeActionContainer::getPictureNameFromBuilding(const core::Building::Type& type) const noexcept {
      const std::string path("data/img/");
      std::string image;
      const std::string extension("_mini.bmp");

      switch (type) {
        case core::Building::Type::MetalMine:
          image = std::string("metal_mine");
          break;
        case core::Building::Type::CrystalMine:
          image = std::string("crystal_mine");
          break;
        case core::Building::Type::DeuteriumMine:
          image = std::string("deuterium_synthesizer");
          break;
        case core::Building::Type::SolarPlant:
          image = std::string("solar_plant");
          break;
        case core::Building::Type::FusionPlant:
          image = std::string("fusion_plant");
          break;
        case core::Building::Type::MetalStorage:
          image = std::string("metal_storage");
          break;
        case core::Building::Type::CrystalStorage:
          image = std::string("crystal_storage");
          break;
        case core::Building::Type::DeuteriumStorage:
          image = std::string("deuterium_tank");
          break;
        case core::Building::Type::RoboticsFactory:
          image = std::string("robotics_factory");
          break;
        case core::Building::Type::Shipyard:
          image = std::string("shipyard");
          break;
        case core::Building::Type::ResearchLab:
          image = std::string("research_laboratory");
          break;
        case core::Building::Type::AllianceDepot:
          image = std::string("alliance_depot");
          break;
        case core::Building::Type::MissileSilo:
          image = std::string("missile_silo");
          break;
        case core::Building::Type::NaniteFactory:
          image = std::string("nanite_factory");
          break;
        case core::Building::Type::Terraformer:
          image = std::string("terraformer");
          break;
        case core::Building::Type::SpaceDock:
          image = std::string("space_dock");
          break;
        // TODO: Handle solar satellites.
        // case core::Building::Type:::
        default:
          image = std::string("solar_satellite");
          break;
      }

      return path + image + extension;
    }

    inline
    const std::string UpgradeActionContainer::getPictureNameFromResearch(const core::Research::Type& type) const noexcept {
      const std::string path("data/img/");
      std::string image;
      const std::string extension("_tech_mini.bmp");

      switch (type) {
        case core::Research::Type::Laser:
          image = std::string("laser");
          break;
        case core::Research::Type::Ion:
          image = std::string("ions");
          break;
        case core::Research::Type::Hyperspace:
          image = std::string("hyperspace");
          break;
        case core::Research::Type::Plasma:
          image = std::string("plasma");
          break;
        case core::Research::Type::CombustionDrive:
          image = std::string("combustion_drive");
          break;
        case core::Research::Type::ImpulseDrive:
          image = std::string("impulse_drive");
          break;
        case core::Research::Type::HyperspaceDrive:
          image = std::string("hyperspace_drive");
          break;
        case core::Research::Type::Espionage:
          image = std::string("espionage");
          break;
        case core::Research::Type::Computer:
          image = std::string("computer");
          break;
        case core::Research::Type::Astrophysics:
          image = std::string("astrophysics");
          break;
        case core::Research::Type::IRN:
          image = std::string("intergalactic_research_network");
          break;
        case core::Research::Type::Graviton:
          image = std::string("graviton");
          break;
        case core::Research::Type::Weapon:
          image = std::string("weapon");
          break;
        case core::Research::Type::Shielding:
          image = std::string("shielding");
          break;
        case core::Research::Type::Armour:
          image = std::string("armour");
          break;
        case core::Research::Type::Energy:
        default:
          image = std::string("energy");
          break;
      }

      return path + image + extension;
    }

    inline
    const std::string UpgradeActionContainer::getPictureNameFromShip(const core::Ship::Type& type) const noexcept {
      const std::string path("data/img/");
      std::string image;
      const std::string extension("_mini.bmp");

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
    const std::string UpgradeActionContainer::getPictureNameFromDefense(const core::Defense::Type& type) const noexcept {
      const std::string path("data/img/");
      std::string image;
      const std::string extension("_mini.bmp");

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

  }
}

#endif // UPGRADEACTIONCONTAINER_HX