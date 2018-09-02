
#include "DefenseView.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "PictureContainer.h"
#include "ComponentFactory.h"
#include "LabelledPicture.h"

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
      LabelledPictureShPtr missile = createLabelledPictureContainer(
        std::string("missile_launcher"),
        getPictureNameFromDefense(core::Defense::Type::MissileLauncher),
        level0
      );
      LabelledPictureShPtr lightLaser = createLabelledPictureContainer(
        std::string("light_laser"),
        getPictureNameFromDefense(core::Defense::Type::LightLaser),
        level0
      );
      LabelledPictureShPtr heavyLaser = createLabelledPictureContainer(
        std::string("heavy_laser"),
        getPictureNameFromDefense(core::Defense::Type::HeavyLaser),
        level0
      );
      LabelledPictureShPtr gaussCannon = createLabelledPictureContainer(
        std::string("gauss_cannon"),
        getPictureNameFromDefense(core::Defense::Type::GaussCannon),
        level0
      );
      LabelledPictureShPtr ionCannon = createLabelledPictureContainer(
        std::string("ion_cannon"),
        getPictureNameFromDefense(core::Defense::Type::IonCannon),
        level0
      );
      LabelledPictureShPtr plasmaTurret = createLabelledPictureContainer(
        std::string("plasma_turret"),
        getPictureNameFromDefense(core::Defense::Type::PlasmaTurret),
        level0
      );
      LabelledPictureShPtr smallShield = createLabelledPictureContainer(
        std::string("small_shield_dome"),
        getPictureNameFromDefense(core::Defense::Type::SmallShieldDome),
        level0
      );
      LabelledPictureShPtr largeShield = createLabelledPictureContainer(
        std::string("large_shield_dome"),
        getPictureNameFromDefense(core::Defense::Type::LargeShieldDome),
        level0
      );
      LabelledPictureShPtr abm = createLabelledPictureContainer(
        std::string("antiballistic_missile"),
        getPictureNameFromDefense(core::Defense::Type::AntiballisticMissile),
        level0
      );
      LabelledPictureShPtr ipm = createLabelledPictureContainer(
        std::string("interplanetary_missile"),
        getPictureNameFromDefense(core::Defense::Type::InterplanetaryMissile),
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
      LabelledPicture* missile = getChild<LabelledPicture*>(std::string("missile_launcher"));
      if (checkChild(missile, "Planet missile launcher")) {
        missile->setLabel(getDefenseCountFromType(core::Defense::Type::MissileLauncher, planet));
      }
      LabelledPicture* lightLaser = getChild<LabelledPicture*>(std::string("light_laser"));
      if (checkChild(lightLaser, "Planet light laser")) {
        lightLaser->setLabel(getDefenseCountFromType(core::Defense::Type::LightLaser, planet));
      }
      LabelledPicture* heavyLaser = getChild<LabelledPicture*>(std::string("heavy_laser"));
      if (checkChild(heavyLaser, "Planet heavy laser")) {
        heavyLaser->setLabel(getDefenseCountFromType(core::Defense::Type::HeavyLaser, planet));
      }
      LabelledPicture* gaussCannon = getChild<LabelledPicture*>(std::string("gauss_cannon"));
      if (checkChild(gaussCannon, "Planet gauss cannon")) {
        gaussCannon->setLabel(getDefenseCountFromType(core::Defense::Type::GaussCannon, planet));
      }
      LabelledPicture* ionCannon = getChild<LabelledPicture*>(std::string("ion_cannon"));
      if (checkChild(ionCannon, "Planet ion cannon")) {
        ionCannon->setLabel(getDefenseCountFromType(core::Defense::Type::IonCannon, planet));
      }
      LabelledPicture* plasmaTurret = getChild<LabelledPicture*>(std::string("plasma_turret"));
      if (checkChild(plasmaTurret, "Planet plasma turret")) {
        plasmaTurret->setLabel(getDefenseCountFromType(core::Defense::Type::PlasmaTurret, planet));
      }

      LabelledPicture* smallShield = getChild<LabelledPicture*>(std::string("small_shield_dome"));
      if (checkChild(smallShield, "Planet small shield dome")) {
        smallShield->setLabel(getDefenseCountFromType(core::Defense::Type::SmallShieldDome, planet));
      }
      LabelledPicture* largeShield = getChild<LabelledPicture*>(std::string("large_shield_dome"));
      if (checkChild(largeShield, "Planet large shield dome")) {
        largeShield->setLabel(getDefenseCountFromType(core::Defense::Type::LargeShieldDome, planet));
      }

      LabelledPicture* abm = getChild<LabelledPicture*>(std::string("antiballistic_missile"));
      if (checkChild(abm, "Planet antiballistic missile")) {
        abm->setLabel(getDefenseCountFromType(core::Defense::Type::AntiballisticMissile, planet));
      }
      LabelledPicture* ipm = getChild<LabelledPicture*>(std::string("interplanetary_missile"));
      if (checkChild(ipm, "Planet interplanetary missile")) {
        ipm->setLabel(getDefenseCountFromType(core::Defense::Type::InterplanetaryMissile, planet));
      }

      makeDeepDirty();
      unlock();
    }
  }
}
