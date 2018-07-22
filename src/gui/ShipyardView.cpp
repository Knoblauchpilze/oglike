
#include "ShipyardView.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "PictureContainer.h"
#include "ComponentFactory.h"
#include "LabelledPicture.h"

namespace ogame {
  namespace gui {

    ShipyardView::ShipyardView(const std::string& name, player::GeneralDataModelShPtr model):
      AbstractBuyingView(name, model)
    {
      createView(model);

      connectDataModel(model);
    }

    ShipyardView::~ShipyardView() {}

    void ShipyardView::createView(player::GeneralDataModelShPtr model) {
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(7u, 5u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create shipyard view"));
      }

      PictureContainerShPtr image = ComponentFactory::createPicturePanel(std::string("image_panel"), std::string("data/img/shipyard_bg.bmp"));

      std::string level0 = std::to_string(0);
      LabelledPictureShPtr lightFighter = createLabelledPictureContainer(std::string("light_fighter"), std::string("data/img/light_fighter.bmp"), level0);
      LabelledPictureShPtr heavyFighter = createLabelledPictureContainer(std::string("heavy_fighter"), std::string("data/img/heavy_fighter.bmp"), level0);
      LabelledPictureShPtr cruiser = createLabelledPictureContainer(std::string("cruiser"), std::string("data/img/cruiser.bmp"), level0);
      LabelledPictureShPtr battleship = createLabelledPictureContainer(std::string("battleship"), std::string("data/img/battleship.bmp"), level0);
      LabelledPictureShPtr smallCargo = createLabelledPictureContainer(std::string("small_cargo"), std::string("data/img/small_cargo_ship.bmp"), level0);
      LabelledPictureShPtr largeCargo = createLabelledPictureContainer(std::string("large_cargo"), std::string("data/img/large_cargo_ship.bmp"), level0);
      LabelledPictureShPtr colonyShip = createLabelledPictureContainer(std::string("colony_ship"), std::string("data/img/colony_ship.bmp"), level0);
      LabelledPictureShPtr battlecruiser = createLabelledPictureContainer(std::string("battlecruiser"), std::string("data/img/battlecruiser.bmp"), level0);
      LabelledPictureShPtr bomber = createLabelledPictureContainer(std::string("bomber"), std::string("data/img/bomber.bmp"), level0);
      LabelledPictureShPtr destroyer = createLabelledPictureContainer(std::string("destroyer"), std::string("data/img/destroyer.bmp"), level0);
      LabelledPictureShPtr deathstar = createLabelledPictureContainer(std::string("deathstar"), std::string("data/img/deathstar.bmp"), level0);
      LabelledPictureShPtr recycler = createLabelledPictureContainer(std::string("recycler"), std::string("data/img/recycler.bmp"), level0);
      LabelledPictureShPtr espionageProbe = createLabelledPictureContainer(std::string("espionage_probe"), std::string("data/img/espionage_probe.bmp"), level0);
      LabelledPictureShPtr solarSatellite = createLabelledPictureContainer(std::string("solar_satellite"), std::string("data/img/solar_satellite.bmp"), level0);

      if (lightFighter == nullptr ||
          heavyFighter == nullptr ||
          cruiser == nullptr ||
          battleship == nullptr ||
          smallCargo == nullptr ||
          largeCargo == nullptr ||
          colonyShip == nullptr ||
          battlecruiser == nullptr ||
          bomber == nullptr ||
          destroyer == nullptr ||
          deathstar == nullptr ||
          recycler == nullptr ||
          espionageProbe == nullptr ||
          solarSatellite == nullptr)
      {
        throw GuiException(std::string("Could not allocate memory to create shipyard view"));
      }

      layout->addItem(image,          0u, 0u, 7u, 2u);
      addChild(image);
      layout->addItem(lightFighter,   0u, 2u, 1u, 1u);
      addChild(lightFighter);
      layout->addItem(heavyFighter,   1u, 2u, 1u, 1u);
      addChild(heavyFighter);
      layout->addItem(cruiser,        2u, 2u, 1u, 1u);
      addChild(cruiser);
      layout->addItem(battleship,     3u, 2u, 1u, 1u);
      addChild(battleship);
      layout->addItem(smallCargo,     4u, 2u, 1u, 1u);
      addChild(smallCargo);
      layout->addItem(largeCargo,     5u, 2u, 1u, 1u);
      addChild(largeCargo);
      layout->addItem(colonyShip,     6u, 2u, 1u, 1u);
      addChild(colonyShip);
      layout->addItem(battlecruiser,  0u, 3u, 1u, 1u);
      addChild(battlecruiser);
      layout->addItem(bomber,         1u, 3u, 1u, 1u);
      addChild(bomber);
      layout->addItem(destroyer,      2u, 3u, 1u, 1u);
      addChild(destroyer);
      layout->addItem(deathstar,      3u, 3u, 1u, 1u);
      addChild(deathstar);
      layout->addItem(recycler,       4u, 3u, 1u, 1u);
      addChild(recycler);
      layout->addItem(espionageProbe, 5u, 3u, 1u, 1u);
      addChild(espionageProbe);
      layout->addItem(solarSatellite, 6u, 3u, 1u, 1u);
      addChild(solarSatellite);

      setLayout(layout);
    }

    void ShipyardView::connectDataModel(player::GeneralDataModelShPtr dataModel) {
      dataModel->registerForAction(player::Action::ChangePlanet, this);
    }

    void ShipyardView::populateWithData(const core::Planet& planet, const core::Account& account) {
      lock();

      // Update each information.
      LabelledPicture* lightFighter = getChild<LabelledPicture*>(std::string("light_fighter"));
      if (checkChild(lightFighter, "Planet light fighter")) {
        lightFighter->setLabel(getShipCountFromType(core::Ship::Type::LightFighter, planet));
      }
      LabelledPicture* heavyFighter = getChild<LabelledPicture*>(std::string("heavy_fighter"));
      if (checkChild(heavyFighter, "Planet heavy fighter")) {
        heavyFighter->setLabel(getShipCountFromType(core::Ship::Type::HeavyFighter, planet));
      }
      LabelledPicture* cruiser = getChild<LabelledPicture*>(std::string("cruiser"));
      if (checkChild(cruiser, "Planet cruiser")) {
        cruiser->setLabel(getShipCountFromType(core::Ship::Type::Cruiser, planet));
      }
      LabelledPicture* battleship = getChild<LabelledPicture*>(std::string("battleship"));
      if (checkChild(battleship, "Planet battleship")) {
        battleship->setLabel(getShipCountFromType(core::Ship::Type::Battleship, planet));
      }

      LabelledPicture* smallCargo = getChild<LabelledPicture*>(std::string("small_cargo"));
      if (checkChild(smallCargo, "Planet small cargo")) {
        smallCargo->setLabel(getShipCountFromType(core::Ship::Type::SmallCargo, planet));
      }
      LabelledPicture* largeCargo = getChild<LabelledPicture*>(std::string("large_cargo"));
      if (checkChild(largeCargo, "Planet large cargo")) {
        largeCargo->setLabel(getShipCountFromType(core::Ship::Type::LargeCargo, planet));
      }
      LabelledPicture* colonyShip = getChild<LabelledPicture*>(std::string("colony_ship"));
      if (checkChild(colonyShip, "Planet colony ship")) {
        colonyShip->setLabel(getShipCountFromType(core::Ship::Type::ColonyShip, planet));
      }

      LabelledPicture* battlecruiser = getChild<LabelledPicture*>(std::string("battlecruiser"));
      if (checkChild(battlecruiser, "Planet battlecruiser")) {
        battlecruiser->setLabel(getShipCountFromType(core::Ship::Type::Battlecruiser, planet));
      }
      LabelledPicture* bomber = getChild<LabelledPicture*>(std::string("bomber"));
      if (checkChild(bomber, "Planet bomber")) {
        bomber->setLabel(getShipCountFromType(core::Ship::Type::Bomber, planet));
      }
      LabelledPicture* destroyer = getChild<LabelledPicture*>(std::string("destroyer"));
      if (checkChild(destroyer, "Planet destoyer")) {
        destroyer->setLabel(getShipCountFromType(core::Ship::Type::Destroyer, planet));
      }
      LabelledPicture* deathstar = getChild<LabelledPicture*>(std::string("deathstar"));
      if (checkChild(deathstar, "Planet deathstar")) {
        deathstar->setLabel(getShipCountFromType(core::Ship::Type::Deathstar, planet));
      }

      LabelledPicture* recycler = getChild<LabelledPicture*>(std::string("recycler"));
      if (checkChild(recycler, "Planet recycler")) {
        recycler->setLabel(getShipCountFromType(core::Ship::Type::Recycler, planet));
      }
      LabelledPicture* espionageProbe = getChild<LabelledPicture*>(std::string("espionage_probe"));
      if (checkChild(espionageProbe, "Planet espionage probe")) {
        espionageProbe->setLabel(getShipCountFromType(core::Ship::Type::EspionageProbe, planet));
      }
      LabelledPicture* satellite = getChild<LabelledPicture*>(std::string("solar_satellite"));
      if (checkChild(satellite, "Planet solar satellite")) {
        satellite->setLabel(getShipCountFromType(core::Ship::Type::SolarSatellite, planet));
      }

      makeDeepDirty();
      unlock();
    }
  }
}
