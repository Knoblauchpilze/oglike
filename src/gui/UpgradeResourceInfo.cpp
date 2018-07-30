
#include "UpgradeResourceInfo.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "ComponentFactory.h"
#include "SwitchPictureContainer.h"
#include "PlanetException.h"

namespace ogame {
  namespace gui {

    UpgradeResourceInfo::UpgradeResourceInfo(const std::string& name,
                                             player::GeneralDataModelShPtr model):
      view::GraphicContainer(name,
                             view::utils::Area()),
      view::GraphicContainerListener(),
      player::GeneralActionListener(model.get())
    {
      createView();
    }

    UpgradeResourceInfo::~UpgradeResourceInfo() {}

    void UpgradeResourceInfo::onInteractionPerformed(const std::string& origin, const view::EventListener::Interaction::Mask& mask) {
      if (mask == view::EventListener::Interaction::MouseButtonReleased) {
        // We need to trigger an upgrade action or a construction action.
        player::GeneralDataModel& dataModel = getDataModel();
        // Retrieve the active view: this way we can determine which element we should use to perform upgrade.
        const player::View& activeView = dataModel.getActiveView();
        core::Planet& planet = dataModel.getActivePlanet();
        core::Account& account = dataModel.getActiveAccount();

        // Create the correct upgrade action.
        try {
          switch (activeView) {
            case player::View::Resources:
              createUpgradeBuildingAction(planet, dataModel);
              break;
            case player::View::Facilities:
              createUpgradeBuildingAction(planet, dataModel);
              break;
            case player::View::Research:
              createUpgradeResearchAction(account, dataModel);
              break;
            case player::View::Shipyard:
              createUpgradeShipAction(planet, dataModel);
              break;
            case player::View::Defense:
              createUpgradeDefenseAction(planet, dataModel);
              break;
            case player::View::Fleet:
            default:
              break;
          }

          lock();

          SwitchPictureContainer* upgrade = getChild<SwitchPictureContainer*>(std::string("upgrade_label"));
          if (checkChild(upgrade, std::string("Upgrade resource info upgrade button"))) {
            upgrade->updateStatus(false);
          }

          unlock();
        }
        catch (const core::PlanetException& e) {
          std::cerr << "[UPGRADE] Could not process upgrade request from " << origin << " on planet " << planet.getName() << ":" << std::endl << e.what() << std::endl;
        }
        catch (const GuiException& e) {
          std::cerr << "[UPGRADE] Could not process upgrade request from " << origin << " on planet " << planet.getName() << ":" << std::endl << e.what() << std::endl;
        }
      }
    }

    void UpgradeResourceInfo::createView() {
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(6u, 4u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create upgrade resource info panel"));
      }

      LabelContainerShPtr title = createLabelPanel(
        std::string("title"),
        std::string("Resources needed:"),
        SDL_Color{128, 128, 128, SDL_ALPHA_OPAQUE}
      );
      LabelledPictureShPtr metal = createLabelledPicturePanel(
        std::string("metal_needed"),
        std::string("data/img/metal.bmp"),
        std::to_string(0u)
      );
      LabelledPictureShPtr crystal = createLabelledPicturePanel(
        std::string("crystal_needed"),
        std::string("data/img/crystal.bmp"),
        std::to_string(0u)
      );
      LabelledPictureShPtr deut = createLabelledPicturePanel(
        std::string("deut_needed"),
        std::string("data/img/deuterium.bmp"),
        std::to_string(0u)
      );
      LabelledPictureShPtr energy = createLabelledPicturePanel(
        std::string("energy_needed"),
        std::string("data/img/energy.bmp"),
        std::to_string(0u)
      );
      SwitchPictureContainerShPtr upgrade = ComponentFactory::createSwitchPicturePanel(
        std::string("upgrade_label"),
        std::string("data/img/button_ok.bmp"),
        std::string("data/img/button_nok.bmp"),
        view::EventListener::Interaction::MouseButtonReleased
      );

      if (title == nullptr ||
          metal == nullptr ||
          crystal == nullptr ||
          deut == nullptr ||
          energy == nullptr ||
          upgrade == nullptr)
      {
        throw GuiException(std::string("Could not allocate memory to create upgrade resource info panel"));
      }

      layout->addItem(title,   0u, 0u, 6u, 1u);
      addChild(title);
      layout->addItem(metal,   0u, 1u, 1u, 2u);
      addChild(metal);
      layout->addItem(crystal, 1u, 1u, 1u, 2u);
      addChild(crystal);
      layout->addItem(deut,    2u, 1u, 1u, 2u);
      addChild(deut);
      layout->addItem(energy,  3u, 1u, 1u, 2u);
      addChild(energy);
      layout->addItem(upgrade, 4u, 1u, 2u, 2u);
      addChild(upgrade);

      setLayout(layout);

      upgrade->addEventListener(this);
    }

  }
}
