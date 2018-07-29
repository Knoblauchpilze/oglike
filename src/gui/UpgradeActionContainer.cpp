
#include "UpgradeActionContainer.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "PictureContainer.h"
#include "ComponentFactory.h"

namespace ogame {
  namespace gui {

    UpgradeActionContainer::UpgradeActionContainer(const std::string& name):
      SelectorPanel(name,
                    view::EventListener::Interaction::NoInteraction,
                    false)
    {
      setBackgroundColor(SDL_Color{28, 33, 38, SDL_ALPHA_OPAQUE});

      createView();
    }

    UpgradeActionContainer::~UpgradeActionContainer() {}

    void UpgradeActionContainer::populateWithBuildingData(const core::Planet& planet) {
      try {
        // Retrieve the building upgrades action and display the first one.
        const std::vector<core::BuildingUpgradeActionShPtr>& upgrades = planet.getBuildingUpgrades();
        bool hasBuildingUpgrade = !upgrades.empty();
        const core::BuildingUpgradeAction* upgrade = nullptr;
        if (hasBuildingUpgrade) {
          upgrade = upgrades[0u].get();
        }

        if (hasBuildingUpgrade) {
          populatePanel(
            std::string("Buildings"),
            upgrade->getName(),
            getPictureNameFromBuilding(upgrade->getType()),
            upgrade->getDescription(),
            (
              upgrade->isFinished() ?
              std::string("done") :
              computeDisplayTime(upgrade->getRemainingTime())
            )
          );
        }
        else {
          clearPanel(std::string("Buildings"),
                     std::string("No buildings in construction"));
        }
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[DURATION] Could not populate upgrade action container " << getName() << " with building actions for planet " << planet.getName() << ":" << std::endl << e.what() << std::endl;
      }
    }

    void UpgradeActionContainer::populateWithResearchData(const core::Account& account) {
      try {
        // Retrieve the building upgrades action and display the first one.
        const std::vector<core::ResearchUpgradeActionShPtr>& upgrades = account.getResearchUpgrades();
        bool hasResearchUpgrade = !upgrades.empty();
        const core::ResearchUpgradeAction* upgrade = nullptr;
        if (hasResearchUpgrade) {
          upgrade = upgrades[0u].get();
        }

        if (hasResearchUpgrade) {
          populatePanel(
            std::string("Research"),
            upgrade->getName(),
            getPictureNameFromResearch(upgrade->getType()),
            upgrade->getDescription(),
            (
              upgrade->isFinished() ?
              std::string("done") :
              computeDisplayTime(upgrade->getRemainingTime())
            )
          );
        }
        else {
          clearPanel(std::string("Research"),
                     std::string("No research in progress at the moment"));
        }
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[DURATION] Could not populate upgrade action container " << getName() << " with research actions for account " << account.getPlayerName() << ":" << std::endl << e.what() << std::endl;
      }
    }

    void UpgradeActionContainer::populateWithShipyardData(const core::Planet& planet) {
      try {
        // Retrieve the building upgrades action and display the first one.
        const std::vector<core::ShipUpgradeActionShPtr>& upgrades = planet.getShipUpgrades();
        bool hasShipUpgrade = !upgrades.empty();
        const core::ShipUpgradeAction* upgrade = nullptr;
        if (hasShipUpgrade) {
          upgrade = upgrades[0u].get();
        }

        if (hasShipUpgrade) {
          populatePanel(
            std::string("Shipyard"),
            upgrade->getName(),
            getPictureNameFromShip(upgrade->getType()),
            upgrade->getDescription(),
            (
              upgrade->isFinished() ?
              std::string("done") :
              computeDisplayTime(upgrade->getRemainingTime())
            )
          );
        }
        else {
          clearPanel(std::string("Shipyard"),
                     std::string("No ships/defence in construction"));
        }
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[DURATION] Could not populate upgrade action container " << getName() << " with shipyard actions for planet " << planet.getName() << ":" << std::endl << e.what() << std::endl;
      }
    }

    void UpgradeActionContainer::createView() {
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(4u, 5u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create upgrade action container"));
      }

      // Create each element.
      const std::string withUpdateContainerName("update_container");
      const std::string noUpdateContainerName("no_update_container");

      view::GraphicContainerShPtr withUpdateContainer = createUpgradeContainer(withUpdateContainerName);
      view::GraphicContainerShPtr noUpdateContainer = createEmptyContainer(noUpdateContainerName);

      addChild(withUpdateContainer);
      addChild(noUpdateContainer);

      setActiveChild(noUpdateContainerName);
    }

    view::GraphicContainerShPtr UpgradeActionContainer::createUpgradeContainer(const std::string& name) {
      // Create each element.
      view::GraphicContainerShPtr withUpdateContainer = std::make_shared<view::GraphicContainer>(
        name,
        view::utils::Area(),
        view::EventListener::Interaction::NoInteraction,
        true,
        view::EventListener::Sensitivity::Local,
        std::make_shared<view::GridLayout>(4u, 5u, 0.0f)
      );

      LabelContainerShPtr title = createLabel(
        std::string("title"),
        std::string("Default upgrade title"),
        SDL_Color{96, 159, 197, SDL_ALPHA_OPAQUE},
        LabelContainer::Alignment::Center,
        SDL_Color{22, 30, 36, SDL_ALPHA_OPAQUE},
        false
      );

      LabelContainerShPtr upgradeName = createLabel(
        std::string("upgrade_name"),
        std::string("Default upgrade name"),
        SDL_Color{255, 255, 255, SDL_ALPHA_OPAQUE}
      );

      PictureContainerShPtr picture = ComponentFactory::createPicturePanel(std::string("picture"), std::string("data/img/solar_plant_small.bmp"));

      LabelContainerShPtr upgradeDescription = createLabel(
        std::string("upgrade_desc"),
        std::string("Default upgrade description"),
        SDL_Color{96, 159, 197, SDL_ALPHA_OPAQUE}
      );

      LabelContainerShPtr durationLabel = createLabel(
        std::string("duration_label"),
        std::string("Duration:"),
        SDL_Color{255, 255, 255, SDL_ALPHA_OPAQUE}
      );

      LabelContainerShPtr duration = createLabel(
        std::string("duration_value"),
        std::string("0s"),
        SDL_Color{156, 102, 28, SDL_ALPHA_OPAQUE}
      );

      if (title == nullptr ||
          upgradeName == nullptr ||
          picture== nullptr ||
          upgradeDescription == nullptr ||
          durationLabel == nullptr ||
          duration == nullptr ||
          withUpdateContainer == nullptr)
      {
        throw GuiException(std::string("Could not allocate memory to create upgrade action container"));
      }

      withUpdateContainer->addChild(title,              0u, 0u, 4u, 1u);
      withUpdateContainer->addChild(upgradeName,        0u, 1u, 4u, 1u);
      withUpdateContainer->addChild(picture,            0u, 2u, 1u, 3u);
      withUpdateContainer->addChild(upgradeDescription, 1u, 2u, 3u, 1u);
      withUpdateContainer->addChild(durationLabel,      1u, 3u, 3u, 1u);
      withUpdateContainer->addChild(duration,           1u, 4u, 3u, 1u);

      return withUpdateContainer;
    }

    view::GraphicContainerShPtr UpgradeActionContainer::createEmptyContainer(const std::string& name) {
      // Create each element.
      view::GraphicContainerShPtr noUpdateContainer = std::make_shared<view::GraphicContainer>(
        name,
        view::utils::Area(),
        view::EventListener::Interaction::NoInteraction,
        true,
        view::EventListener::Sensitivity::Local,
        std::make_shared<view::GridLayout>(4u, 5u, 0.0f)
      );

      LabelContainerShPtr title = createLabel(
        std::string("title"),
        std::string("Default upgrade title"),
        SDL_Color{96, 159, 197, SDL_ALPHA_OPAQUE},
        LabelContainer::Alignment::Center,
        SDL_Color{22, 30, 36, SDL_ALPHA_OPAQUE},
        false
      );

      LabelContainerShPtr noUpgrades = createLabel(
        std::string("desc"),
        std::string("No upgrade running"),
        SDL_Color{255, 255, 255, SDL_ALPHA_OPAQUE},
        LabelContainer::Alignment::Center,
        SDL_Color{22, 30, 36, SDL_ALPHA_OPAQUE},
        false,
        10
      );

      if (title == nullptr ||
          noUpgrades == nullptr ||
          noUpdateContainer == nullptr)
      {
        throw GuiException(std::string("Could not allocate memory to create upgrade action container"));
      }

      noUpdateContainer->addChild(title,      0u, 0u, 4u, 1u);
      noUpdateContainer->addChild(noUpgrades, 0u, 1u, 4u, 4u);

      return noUpdateContainer;
    }

    void UpgradeActionContainer::populatePanel(const std::string& upgradeType,
                                               const std::string& upgradeName,
                                               const std::string& upgradePicture,
                                               const std::string& upgradeDesc,
                                               const std::string& upgradeDuration)
    {
      view::GraphicContainer* upgradeContainer = getChildFromCompleteList<view::GraphicContainer*>(std::string("update_container"));

      if (checkChild(upgradeContainer, "Upgrade action container main container")) {
        lock();
        // Update each information.
        LabelContainer* title = upgradeContainer->getChild<LabelContainer*>(std::string("title"));
        if (checkChild(title, "Upgrade action container title")) {
          title->setText(upgradeType);
        }

        LabelContainer* name = upgradeContainer->getChild<LabelContainer*>(std::string("upgrade_name"));
        if (checkChild(name, "Upgrade action container upgrade name")) {
          name->setText(upgradeName);
        }

        PictureContainer* picture = upgradeContainer->getChild<PictureContainer*>(std::string("picture"));
        if (checkChild(picture, "Upgrade action container picture")) {
          picture->setImagePath(upgradePicture);
        }

        LabelContainer* desc = upgradeContainer->getChild<LabelContainer*>(std::string("upgrade_desc"));
        if (checkChild(desc, "Upgrade action container description")) {
          desc->setText(upgradeDesc);
        }

        LabelContainer* duration = upgradeContainer->getChild<LabelContainer*>(std::string("duration_value"));
        if (checkChild(duration, "Upgrade action container duration")) {
          duration->setText(upgradeDuration);
        }
        makeDeepDirty();
        unlock();

        setActiveChild("update_container");
      }
    }

    void UpgradeActionContainer::clearPanel(const std::string& upgradeType,
                                            const std::string& upgradeDesc)
    {
      view::GraphicContainer* noUpgradeContainer = getChildFromCompleteList<view::GraphicContainer*>(std::string("no_update_container"));

      if (checkChild(noUpgradeContainer, "Upgrade action container main container")) {
        lock();
        // Update each information.
        LabelContainer* title = noUpgradeContainer->getChild<LabelContainer*>(std::string("title"));
        if (checkChild(title, "Upgrade action container title")) {
          title->setText(upgradeType);
        }

        LabelContainer* desc = noUpgradeContainer->getChild<LabelContainer*>(std::string("desc"));
        if (checkChild(desc, "Upgrade action container title")) {
          desc->setText(upgradeDesc);
        }

        makeDeepDirty();
        unlock();

        setActiveChild("no_update_container");
      }
    }

  }
}
