
#include "DefenseView.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    DefenseView::DefenseView(const std::string& name, player::GeneralDataModelShPtr model):
      AbstractBuyingView(name,
                         model,
                         6u,
                         5u,
                         std::string("data/img/defense_bg.bmp"))
    {
      createView();

      connectDataModel(player::Action::ChangePlanet);
    }

    DefenseView::~DefenseView() {}

    void DefenseView::createView() {
      // Create all elements.
      std::string level0 = std::to_string(0);
      BackgroundedLabelShPtr missile = createBackgroundedLabelContainer(
        std::string("missile_launcher"),
        core::Defense::getPictureNameFromDefense(core::Defense::Type::MissileLauncher),
        level0
      );
      BackgroundedLabelShPtr lightLaser = createBackgroundedLabelContainer(
        std::string("light_laser"),
        core::Defense::getPictureNameFromDefense(core::Defense::Type::LightLaser),
        level0
      );
      BackgroundedLabelShPtr heavyLaser = createBackgroundedLabelContainer(
        std::string("heavy_laser"),
        core::Defense::getPictureNameFromDefense(core::Defense::Type::HeavyLaser),
        level0
      );
      BackgroundedLabelShPtr gaussCannon = createBackgroundedLabelContainer(
        std::string("gauss_cannon"),
        core::Defense::getPictureNameFromDefense(core::Defense::Type::GaussCannon),
        level0
      );
      BackgroundedLabelShPtr ionCannon = createBackgroundedLabelContainer(
        std::string("ion_cannon"),
        core::Defense::getPictureNameFromDefense(core::Defense::Type::IonCannon),
        level0
      );
      BackgroundedLabelShPtr plasmaTurret = createBackgroundedLabelContainer(
        std::string("plasma_turret"),
        core::Defense::getPictureNameFromDefense(core::Defense::Type::PlasmaTurret),
        level0
      );
      BackgroundedLabelShPtr smallShield = createBackgroundedLabelContainer(
        std::string("small_shield_dome"),
        core::Defense::getPictureNameFromDefense(core::Defense::Type::SmallShieldDome),
        level0
      );
      BackgroundedLabelShPtr largeShield = createBackgroundedLabelContainer(
        std::string("large_shield_dome"),
        core::Defense::getPictureNameFromDefense(core::Defense::Type::LargeShieldDome),
        level0
      );
      BackgroundedLabelShPtr abm = createBackgroundedLabelContainer(
        std::string("antiballistic_missile"),
        core::Defense::getPictureNameFromDefense(core::Defense::Type::AntiballisticMissile),
        level0
      );
      BackgroundedLabelShPtr ipm = createBackgroundedLabelContainer(
        std::string("interplanetary_missile"),
        core::Defense::getPictureNameFromDefense(core::Defense::Type::InterplanetaryMissile),
        level0
      );

      if (missile == nullptr ||
          lightLaser == nullptr ||
          heavyLaser == nullptr ||
          gaussCannon == nullptr ||
          ionCannon == nullptr ||
          plasmaTurret == nullptr ||
          smallShield == nullptr ||
          largeShield == nullptr ||
          abm == nullptr ||
          ipm == nullptr)
      {
        throw GuiException(std::string("Could not allocate memory to create defense view"));
      }

      addChild(missile,      0u, 2u, 1u, 1u);
      addChild(lightLaser,   1u, 2u, 1u, 1u);
      addChild(heavyLaser,   2u, 2u, 1u, 1u);
      addChild(gaussCannon,  3u, 2u, 1u, 1u);
      addChild(ionCannon,    4u, 2u, 1u, 1u);
      addChild(plasmaTurret, 5u, 2u, 1u, 1u);
      addChild(smallShield,  0u, 3u, 1u, 1u);
      addChild(largeShield,  1u, 3u, 1u, 1u);
      addChild(abm,          2u, 3u, 1u, 1u);
      addChild(ipm,          3u, 3u, 1u, 1u);
    }

    void DefenseView::populateWithPlanetData(const core::Planet& planet) {
      lock();

      // Update each information.
      std::vector<std::pair<std::string, core::Defense::Type>> defenses = {
        {std::string("missile_launcher"), core::Defense::Type::MissileLauncher},
        {std::string("light_laser"), core::Defense::Type::LightLaser},
        {std::string("heavy_laser"), core::Defense::Type::HeavyLaser},

        {std::string("gauss_cannon"), core::Defense::Type::GaussCannon},
        {std::string("ion_cannon"), core::Defense::Type::IonCannon},
        {std::string("plasma_turret"), core::Defense::Type::PlasmaTurret},

        {std::string("small_shield_dome"), core::Defense::Type::SmallShieldDome},
        {std::string("large_shield_dome"), core::Defense::Type::LargeShieldDome},

        {std::string("antiballistic_missile"), core::Defense::Type::AntiballisticMissile},
        {std::string("interplanetary_missile"), core::Defense::Type::InterplanetaryMissile}
      };

      std::for_each(defenses.cbegin(), defenses.cend(),
        [this, &planet](const std::pair<std::string, core::Defense::Type>& defense) {
          BackgroundedLabel* defenseInfo = getChild<BackgroundedLabel*>(defense.first);
          if (checkChild(defenseInfo, defense.first)) {
            defenseInfo->setText(getDefenseCountFromType(defense.second, planet));
          }
        }
      );

      makeDeepDirty();
      unlock();
    }
  }
}
