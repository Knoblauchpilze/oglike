
#include "FleetView.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "PictureContainer.h"
#include "ComponentFactory.h"
#include "LabelledPicture.h"

namespace ogame {
  namespace gui {

    FleetView::FleetView(const std::string& name, player::GeneralDataModelShPtr model):
      AbstractBuyingView(name,
                         model,
                         7u,
                         5u,
                         std::string("data/img/fleet_bg.bmp"))
    {
      createView();

      connectDataModel(player::Action::ChangePlanet);
    }

    FleetView::~FleetView() {}

    void FleetView::createView() {
      // Create all elements.
      std::string level0 = std::to_string(0);
      LabelledPictureShPtr lightFighter = createLabelledPictureContainer(
        std::string("light_fighter"),
        getPictureNameFromShip(core::Ship::Type::LightFighter),
        level0
      );
      LabelledPictureShPtr heavyFighter = createLabelledPictureContainer(
        std::string("heavy_fighter"),
        getPictureNameFromShip(core::Ship::Type::HeavyFighter),
        level0
      );
      LabelledPictureShPtr cruiser = createLabelledPictureContainer(
        std::string("cruiser"),
        getPictureNameFromShip(core::Ship::Type::Cruiser),
        level0
      );
      LabelledPictureShPtr battleship = createLabelledPictureContainer(
        std::string("battleship"),
        getPictureNameFromShip(core::Ship::Type::Battleship),
        level0
      );
      LabelledPictureShPtr smallCargo = createLabelledPictureContainer(
        std::string("small_cargo"),
        getPictureNameFromShip(core::Ship::Type::SmallCargo),
        level0
      );
      LabelledPictureShPtr largeCargo = createLabelledPictureContainer(
        std::string("large_cargo"),
        getPictureNameFromShip(core::Ship::Type::LargeCargo),
        level0
      );
      LabelledPictureShPtr colonyShip = createLabelledPictureContainer(
        std::string("colony_ship"),
        getPictureNameFromShip(core::Ship::Type::ColonyShip),
        level0
      );
      LabelledPictureShPtr battlecruiser = createLabelledPictureContainer(
        std::string("battlecruiser"),
        getPictureNameFromShip(core::Ship::Type::Battlecruiser),
        level0
      );
      LabelledPictureShPtr bomber = createLabelledPictureContainer(
        std::string("bomber"),
        getPictureNameFromShip(core::Ship::Type::Bomber),
        level0
      );
      LabelledPictureShPtr destroyer = createLabelledPictureContainer(
        std::string("destroyer"),
        getPictureNameFromShip(core::Ship::Type::Destroyer),
        level0
      );
      LabelledPictureShPtr deathstar = createLabelledPictureContainer(
        std::string("deathstar"),
        getPictureNameFromShip(core::Ship::Type::Deathstar),
        level0
      );
      LabelledPictureShPtr recycler = createLabelledPictureContainer(
        std::string("recycler"),
        getPictureNameFromShip(core::Ship::Type::Recycler),
        level0
      );
      LabelledPictureShPtr espionageProbe = createLabelledPictureContainer(
        std::string("espionage_probe"),
        getPictureNameFromShip(core::Ship::Type::EspionageProbe),
        level0
      );
      LabelledPictureShPtr solarSatellite = createLabelledPictureContainer(
        std::string("solar_satellite"),
        getPictureNameFromShip(core::Ship::Type::SolarSatellite),
        level0
      );

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
        throw GuiException(std::string("Could not allocate memory to create fleet view"));
      }

      addChild(lightFighter,   0u, 2u, 1u, 1u);
      addChild(heavyFighter,   1u, 2u, 1u, 1u);
      addChild(cruiser,        2u, 2u, 1u, 1u);
      addChild(battleship,     3u, 2u, 1u, 1u);
      addChild(smallCargo,     4u, 2u, 1u, 1u);
      addChild(largeCargo,     5u, 2u, 1u, 1u);
      addChild(colonyShip,     6u, 2u, 1u, 1u);
      addChild(battlecruiser,  0u, 3u, 1u, 1u);
      addChild(bomber,         1u, 3u, 1u, 1u);
      addChild(destroyer,      2u, 3u, 1u, 1u);
      addChild(deathstar,      3u, 3u, 1u, 1u);
      addChild(recycler,       4u, 3u, 1u, 1u);
      addChild(espionageProbe, 5u, 3u, 1u, 1u);
      addChild(solarSatellite, 6u, 3u, 1u, 1u);
    }

    void FleetView::populateWithPlanetData(const core::Planet& planet) {
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
