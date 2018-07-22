
#include "DefenseView.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "PictureContainer.h"
#include "ComponentFactory.h"
#include "LabelledPicture.h"

namespace ogame {
  namespace gui {

    DefenseView::DefenseView(const std::string& name, player::GeneralDataModelShPtr model):
      AbstractBuyingView(name, model)
    {
      createView(model);

      connectDataModel(model);
    }

    DefenseView::~DefenseView() {}

    void DefenseView::createView(player::GeneralDataModelShPtr model) {
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(6u, 5u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create defense view"));
      }

      PictureContainerShPtr image = ComponentFactory::createPicturePanel(std::string("image_panel"), std::string("data/img/defense_bg.bmp"));

      std::string level0 = std::to_string(0);
      LabelledPictureShPtr missile = createLabelledPictureContainer(std::string("missile_launcher"), std::string("data/img/missile_launcher.bmp"), level0);
      LabelledPictureShPtr lightLaser = createLabelledPictureContainer(std::string("light_laser"), std::string("data/img/light_laser.bmp"), level0);
      LabelledPictureShPtr heavyLaser = createLabelledPictureContainer(std::string("heavy_laser"), std::string("data/img/heavy_laser.bmp"), level0);
      LabelledPictureShPtr gaussCannon = createLabelledPictureContainer(std::string("gauss_cannon"), std::string("data/img/gauss_cannon.bmp"), level0);
      LabelledPictureShPtr ionCannon = createLabelledPictureContainer(std::string("ion_cannon"), std::string("data/img/ion_cannon.bmp"), level0);
      LabelledPictureShPtr plasmaTurret = createLabelledPictureContainer(std::string("plasma_turret"), std::string("data/img/plasma_turret.bmp"), level0);
      LabelledPictureShPtr smallShield = createLabelledPictureContainer(std::string("small_shield_dome"), std::string("data/img/small_shield_dome.bmp"), level0);
      LabelledPictureShPtr largeShield = createLabelledPictureContainer(std::string("large_shield_dome"), std::string("data/img/large_shield_dome.bmp"), level0);
      LabelledPictureShPtr abm = createLabelledPictureContainer(std::string("antiballistic_missile"), std::string("data/img/antiballistic_missile.bmp"), level0);
      LabelledPictureShPtr ipm = createLabelledPictureContainer(std::string("interplanetary_missile"), std::string("data/img/interplanetary_missile.bmp"), level0);

      if (image == nullptr ||
          missile == nullptr ||
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

      layout->addItem(image,        0u, 0u, 6u, 2u);
      addChild(image);
      layout->addItem(missile,      0u, 2u, 1u, 1u);
      addChild(missile);
      layout->addItem(lightLaser,   1u, 2u, 1u, 1u);
      addChild(lightLaser);
      layout->addItem(heavyLaser,   2u, 2u, 1u, 1u);
      addChild(heavyLaser);
      layout->addItem(gaussCannon,  3u, 2u, 1u, 1u);
      addChild(gaussCannon);
      layout->addItem(ionCannon,    4u, 2u, 1u, 1u);
      addChild(ionCannon);
      layout->addItem(plasmaTurret, 5u, 2u, 1u, 1u);
      addChild(plasmaTurret);
      layout->addItem(smallShield,  0u, 3u, 1u, 1u);
      addChild(smallShield);
      layout->addItem(largeShield,  1u, 3u, 1u, 1u);
      addChild(largeShield);
      layout->addItem(abm,          2u, 3u, 1u, 1u);
      addChild(abm);
      layout->addItem(ipm,          3u, 3u, 1u, 1u);
      addChild(ipm);

      setLayout(layout);
    }

    void DefenseView::connectDataModel(player::GeneralDataModelShPtr dataModel) {
      dataModel->registerForAction(player::Action::ChangePlanet, this);
    }

    void DefenseView::populateWithData(const core::Planet& planet, const core::Account& account) {
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
