
#include "ShipyardView.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    ShipyardView::ShipyardView(const std::string& name, player::GeneralDataModelShPtr model):
      AbstractBuyingView(name,
                         model,
                         7u,
                         5u,
                         std::string("data/img/shipyard_bg.bmp"))
    {
      createView();

      connectDataModel(player::Action::ChangePlanet);
    }

    ShipyardView::~ShipyardView() {}

    void ShipyardView::createView() {
      // Create all elements.
      std::string level0 = std::to_string(0);
      BackgroundedLabelShPtr lightFighter = createBackgroundedLabelContainer(
        std::string("light_fighter"),
        getPictureNameFromShip(core::Ship::Type::LightFighter),
        level0
      );
      BackgroundedLabelShPtr heavyFighter = createBackgroundedLabelContainer(
        std::string("heavy_fighter"),
        getPictureNameFromShip(core::Ship::Type::HeavyFighter),
        level0
      );
      BackgroundedLabelShPtr cruiser = createBackgroundedLabelContainer(
        std::string("cruiser"),
        getPictureNameFromShip(core::Ship::Type::Cruiser),
        level0
      );
      BackgroundedLabelShPtr battleship = createBackgroundedLabelContainer(
        std::string("battleship"),
        getPictureNameFromShip(core::Ship::Type::Battleship),
        level0
      );
      BackgroundedLabelShPtr smallCargo = createBackgroundedLabelContainer(
        std::string("small_cargo"),
        getPictureNameFromShip(core::Ship::Type::SmallCargo),
        level0
      );
      BackgroundedLabelShPtr largeCargo = createBackgroundedLabelContainer(
        std::string("large_cargo"),
        getPictureNameFromShip(core::Ship::Type::LargeCargo),
        level0
      );
      BackgroundedLabelShPtr colonyShip = createBackgroundedLabelContainer(
        std::string("colony_ship"),
        getPictureNameFromShip(core::Ship::Type::ColonyShip),
        level0
      );
      BackgroundedLabelShPtr battlecruiser = createBackgroundedLabelContainer(
        std::string("battlecruiser"),
        getPictureNameFromShip(core::Ship::Type::Battlecruiser),
        level0
      );
      BackgroundedLabelShPtr bomber = createBackgroundedLabelContainer(
        std::string("bomber"),
        getPictureNameFromShip(core::Ship::Type::Bomber),
        level0
      );
      BackgroundedLabelShPtr destroyer = createBackgroundedLabelContainer(
        std::string("destroyer"),
        getPictureNameFromShip(core::Ship::Type::Destroyer),
        level0
      );
      BackgroundedLabelShPtr deathstar = createBackgroundedLabelContainer(
        std::string("deathstar"),
        getPictureNameFromShip(core::Ship::Type::Deathstar),
        level0
      );
      BackgroundedLabelShPtr recycler = createBackgroundedLabelContainer(
        std::string("recycler"),
        getPictureNameFromShip(core::Ship::Type::Recycler),
        level0
      );
      BackgroundedLabelShPtr espionageProbe = createBackgroundedLabelContainer(
        std::string("espionage_probe"),
        getPictureNameFromShip(core::Ship::Type::EspionageProbe),
        level0
      );
      BackgroundedLabelShPtr solarSatellite = createBackgroundedLabelContainer(
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
        throw GuiException(std::string("Could not allocate memory to create shipyard view"));
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

    void ShipyardView::populateWithPlanetData(const core::Planet& planet) {
      lock();

      // Update each information.
      std::vector<std::pair<std::string, core::Ship::Type>> ships = {
        {std::string("light_fighter"), core::Ship::Type::LightFighter},
        {std::string("heavy_fighter"), core::Ship::Type::HeavyFighter},
        {std::string("cruiser"), core::Ship::Type::Cruiser},
        {std::string("battleship"), core::Ship::Type::Battleship},

        {std::string("small_cargo"), core::Ship::Type::SmallCargo},
        {std::string("large_cargo"), core::Ship::Type::LargeCargo},
        {std::string("colony_ship"), core::Ship::Type::ColonyShip},

        {std::string("battlecruiser"), core::Ship::Type::Battlecruiser},
        {std::string("bomber"), core::Ship::Type::Bomber},
        {std::string("destroyer"), core::Ship::Type::Destroyer},
        {std::string("deathstar"), core::Ship::Type::Deathstar},

        {std::string("recycler"), core::Ship::Type::Recycler},
        {std::string("espionage_probe"), core::Ship::Type::EspionageProbe},
        {std::string("solar_satellite"), core::Ship::Type::SolarSatellite}
      };

      std::for_each(ships.cbegin(), ships.cend(),
        [this, &planet](const std::pair<std::string, core::Ship::Type>& ship) {
          BackgroundedLabel* shipInfo = getChild<BackgroundedLabel*>(ship.first);
          if (checkChild(shipInfo, ship.first)) {
            shipInfo->setText(getShipCountFromType(ship.second, planet));
          }
        }
      );

      makeDeepDirty();
      unlock();
    }
  }
}
