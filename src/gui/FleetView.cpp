
#include "FleetView.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "PictureContainer.h"
#include "ComponentFactory.h"
#include "LabelledPicture.h"
#include "SwitchPictureContainer.h"

namespace ogame {
  namespace gui {

    FleetView::FleetView(const std::string& name, player::GeneralDataModelShPtr model):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::NoInteraction,
                             false),
      player::GeneralActionListener(model.get())
    {
      // setBackgroundColor(SDL_Color{14, 57, 83, SDL_ALPHA_OPAQUE});

      createView();

      model->registerForAction(player::Action::ChangePlanet, this);
    }

    FleetView::~FleetView() {}

    void FleetView::createView() {
      // Create the layout.
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(7u, 5u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create view ") + getName());
      }

      // Assign the layout.
      setLayout(layout);

      // Create all elements.
      PictureContainerShPtr image = ComponentFactory::createPicturePanel(
        std::string("image_panel"),
        std::string("data/img/fleet_bg.bmp")
      );

      std::string noShip = std::to_string(0);
      ShipSelectionPanelShPtr lightFighter = std::make_shared<ShipSelectionPanel>(
        std::string("light_fighter"),
        core::Ship::Type::LightFighter
      );
      ShipSelectionPanelShPtr heavyFighter = std::make_shared<ShipSelectionPanel>(
        std::string("heavy_fighter"),
        core::Ship::Type::HeavyFighter
      );
      ShipSelectionPanelShPtr cruiser = std::make_shared<ShipSelectionPanel>(
        std::string("cruiser"),
        core::Ship::Type::Cruiser
      );
      ShipSelectionPanelShPtr battleship = std::make_shared<ShipSelectionPanel>(
        std::string("battleship"),
        core::Ship::Type::Battleship
      );
      ShipSelectionPanelShPtr smallCargo = std::make_shared<ShipSelectionPanel>(
        std::string("small_cargo"),
        core::Ship::Type::SmallCargo
      );
      ShipSelectionPanelShPtr largeCargo = std::make_shared<ShipSelectionPanel>(
        std::string("large_cargo"),
        core::Ship::Type::LargeCargo
      );
      ShipSelectionPanelShPtr colonyShip = std::make_shared<ShipSelectionPanel>(
        std::string("colony_ship"),
        core::Ship::Type::ColonyShip
      );
      ShipSelectionPanelShPtr battlecruiser = std::make_shared<ShipSelectionPanel>(
        std::string("battlecruiser"),
        core::Ship::Type::Battlecruiser
      );
      ShipSelectionPanelShPtr bomber = std::make_shared<ShipSelectionPanel>(
        std::string("bomber"),
        core::Ship::Type::Bomber
      );
      ShipSelectionPanelShPtr destroyer = std::make_shared<ShipSelectionPanel>(
        std::string("destroyer"),
        core::Ship::Type::Destroyer
      );
      ShipSelectionPanelShPtr deathstar = std::make_shared<ShipSelectionPanel>(
        std::string("deathstar"),
        core::Ship::Type::Deathstar
      );
      ShipSelectionPanelShPtr recycler = std::make_shared<ShipSelectionPanel>(
        std::string("recycler"),
        core::Ship::Type::Recycler
      );
      ShipSelectionPanelShPtr espionageProbe = std::make_shared<ShipSelectionPanel>(
        std::string("espionage_probe"),
        core::Ship::Type::EspionageProbe
      );
      ShipSelectionPanelShPtr solarSatellite = std::make_shared<ShipSelectionPanel>(
        std::string("solar_satellite"),
        core::Ship::Type::SolarSatellite
      );

      PictureContainerShPtr allShipsIn = ComponentFactory::createPicturePanel(
        std::string("all_ships_in"),
        std::string("data/img/all_in.bmp")
      );

      PictureContainerShPtr allShipsOut = ComponentFactory::createPicturePanel(
        std::string("all_ships_out"),
        std::string("data/img/all_out.bmp")
      );

      SwitchPictureContainerShPtr previousStep = ComponentFactory::createSwitchPicturePanel(
        std::string("previous_step"),
        std::string("data/img/action_return.bmp"),
        std::string("data/img/action_invalid.bmp"),
        view::EventListener::Interaction::MouseButtonPressed
      );

      SwitchPictureContainerShPtr nextStep = ComponentFactory::createSwitchPicturePanel(
        std::string("next_step"),
        std::string("data/img/action_valid.bmp"),
        std::string("data/img/action_invalid.bmp"),
        view::EventListener::Interaction::MouseButtonPressed
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
          solarSatellite == nullptr ||
          allShipsIn == nullptr ||
          allShipsOut == nullptr ||
          previousStep == nullptr ||
          nextStep == nullptr)
      {
        throw GuiException(std::string("Could not allocate memory to create fleet view"));
      }

      // Add the images panel to the layout.
      addChild(image, 0u, 0u, 7u, 2u);
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
      addChild(allShipsIn,     0u, 4u, 1u, 1u);
      addChild(allShipsOut,    1u, 4u, 1u, 1u);
      addChild(previousStep,   3u, 4u, 2u, 1u);
      addChild(nextStep,       5u, 4u, 2u, 1u);
    }

    void FleetView::populateWithPlanetData(const core::Planet& planet) {
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
        {std::string("espionnage_probe"), core::Ship::Type::EspionageProbe},
        {std::string("solar_satellite"), core::Ship::Type::SolarSatellite}
      };

      std::for_each(ships.cbegin(), ships.cend(),
        [this, &planet](const std::pair<std::string, core::Ship::Type>& ship) {
          LabelledPicture* shipInfo = getChild<LabelledPicture*>(ship.first);
          if (checkChild(shipInfo, ship.first)) {
            shipInfo->setLabel(getShipCountFromType(ship.second, planet));
          }
        }
      );

      makeDeepDirty();
      unlock();
    }
  }
}
