
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
      lock();

      try {
        // Retrieve the building upgrades action and display the first one.
        const std::vector<core::BuildingUpgradeActionShPtr>& upgrades = planet.getBuildingUpgrades();
        bool hasBuildingUpgrade = !upgrades.empty();
        const core::BuildingUpgradeAction* upgrade = nullptr;
        if (hasBuildingUpgrade) {
          upgrade = upgrades[0u].get();
        }

        std::cout << "[UPGRADE] Planet " << planet.getName() << " has " << upgrades.size() << " building(s) upgrade(s)" << std::endl;

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
        }
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[DURATION] Could not populate upgrade action container " << getName() << " with building actions for planet " << planet.getName() << ":" << std::endl << e.what() << std::endl;
      }

      makeDeepDirty();
      unlock();
    }

    void UpgradeActionContainer::populateWithResearchData(const core::Account& account) {
      lock();

      try {
        // Retrieve the building upgrades action and display the first one.
        const std::vector<core::ResearchUpgradeActionShPtr>& upgrades = account.getResearchUpgrades();
        bool hasResearchUpgrade = !upgrades.empty();
        const core::ResearchUpgradeAction* upgrade = nullptr;
        if (hasResearchUpgrade) {
          upgrade = upgrades[0u].get();
        }

        std::cout << "[UPGRADE] Planet " << account.getPlayerName() << " has " << upgrades.size() << " research(es) upgrade(s)" << std::endl;

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
        }
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[DURATION] Could not populate upgrade action container " << getName() << " with research actions for account " << account.getPlayerName() << ":" << std::endl << e.what() << std::endl;
      }

      makeDeepDirty();
      unlock();
    }

    void UpgradeActionContainer::populateWithShipyardData(const core::Planet& planet) {
      lock();

      try {
        // Retrieve the building upgrades action and display the first one.
        const std::vector<core::ShipUpgradeActionShPtr>& upgrades = planet.getShipUpgrades();
        bool hasShipUpgrade = !upgrades.empty();
        const core::ShipUpgradeAction* upgrade = nullptr;
        if (hasShipUpgrade) {
          upgrade = upgrades[0u].get();
        }

        std::cout << "[UPGRADE] Planet " << planet.getName() << " has " << upgrades.size() << " shipyard(s) upgrade(s)" << std::endl;

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
        }
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[DURATION] Could not populate upgrade action container " << getName() << " with shipyard actions for planet " << planet.getName() << ":" << std::endl << e.what() << std::endl;
      }

      makeDeepDirty();
      unlock();
    }

    void UpgradeActionContainer::createView() {
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(4u, 5u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create upgrade action container"));
      }

      // Create each element.
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
          duration == nullptr)
      {
        throw GuiException(std::string("Could not allocate memory to create upgrade action container"));
      }

      layout->addItem(title,              0u, 0u, 4u, 1u);
      addChild(title);
      layout->addItem(upgradeName,        0u, 1u, 4u, 1u);
      addChild(upgradeName);
      layout->addItem(picture,            0u, 2u, 1u, 3u);
      addChild(picture);
      layout->addItem(upgradeDescription, 1u, 2u, 3u, 1u);
      addChild(upgradeDescription);
      layout->addItem(durationLabel,      1u, 3u, 3u, 1u);
      addChild(durationLabel);
      layout->addItem(duration,           1u, 4u, 3u, 1u);
      addChild(duration);

      setLayout(layout);
    }

    void UpgradeActionContainer::populatePanel(const std::string& upgradeType,
                                               const std::string& upgradeName,
                                               const std::string& upgradePicture,
                                               const std::string& upgradeDesc,
                                               const std::string& upgradeDuration)
    {
      // Update each information.
      LabelContainer* title = getChild<LabelContainer*>(std::string("title"));
      if (checkChild(title, "Upgrade action container title")) {
        title->setText(upgradeType);
      }

      LabelContainer* name = getChild<LabelContainer*>(std::string("upgrade_name"));
      if (checkChild(name, "Upgrade action container upgrade name")) {
        name->setText(upgradeName);
      }

      PictureContainer* picture = getChild<PictureContainer*>(std::string("picture"));
      if (checkChild(picture, "Upgrade action container picture")) {
        picture->setImagePath(upgradePicture);
      }

      LabelContainer* desc = getChild<LabelContainer*>(std::string("upgrade_desc"));
      if (checkChild(desc, "Upgrade action container description")) {
        desc->setText(upgradeDesc);
      }

      LabelContainer* duration = getChild<LabelContainer*>(std::string("duration_value"));
      if (checkChild(duration, "Upgrade action container duration")) {
        duration->setText(upgradeDuration);
      }
    }

    void UpgradeActionContainer::clearPanel() {}

  }
}
