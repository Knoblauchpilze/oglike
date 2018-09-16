
#include "UpgradeActionContainer.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "PictureContainer.h"
#include "ComponentFactory.h"

namespace ogame {
  namespace gui {

    UpgradeActionContainer::UpgradeActionContainer(const std::string& name,
                                                   const bool multivalued):
      SelectorPanel(name,
                    view::EventListener::Interaction::NoInteraction,
                    false),
      m_multivalued(multivalued)
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
        const std::vector<core::ShipUpgradeActionShPtr>& ships = planet.getShipUpgrades();
        const std::vector<core::DefenseUpgradeActionShPtr>& defenses = planet.getDefenseUpgrades();
        bool hasShipUpgrade = !ships.empty();
        bool hasDefenseUpgrade = !defenses.empty();

        const core::ShipUpgradeAction* shipUpgrade = nullptr;
        if (hasShipUpgrade) {
          shipUpgrade = ships[0u].get();
        }

        const core::DefenseUpgradeAction* defenseUpgrade = nullptr;
        if (hasDefenseUpgrade) {
          defenseUpgrade = defenses[0u].get();
        }

        const bool hasMoreThanOneUpgrade = ships.size() + defenses.size() > 1;

        if (hasShipUpgrade) {
          populatePanel(
            std::string("Shipyard"),
            shipUpgrade->getName(),
            core::Ship::getPictureNameFromShip(shipUpgrade->getType(), false),
            shipUpgrade->getDescription(),
            (
              shipUpgrade->isFinished() ?
              std::string("done") :
              computeDisplayTime(shipUpgrade->getRemainingTime())
            )
          );
        }
        else if (hasDefenseUpgrade) {
          populatePanel(
            std::string("Shipyard"),
            defenseUpgrade->getName(),
            getPictureNameFromDefense(defenseUpgrade->getType()),
            defenseUpgrade->getDescription(),
            (
              defenseUpgrade->isFinished() ?
              std::string("done") :
              computeDisplayTime(defenseUpgrade->getRemainingTime())
            )
          );
        }
        else {
          clearPanel(std::string("Shipyard"),
                     std::string("No ships/defence in construction"));
        }

        if (hasMoreThanOneUpgrade && m_multivalued) {
          // Populate the photo gallery with the rest of the upgrades.
          addToPhotoGallery(ships, hasShipUpgrade, true);
          addToPhotoGallery(defenses, !hasShipUpgrade, false);
        }
        if (!hasMoreThanOneUpgrade) {
          // Clear the gallery from previously added upgrades.
          view::GraphicContainer* upgradeContainer = getChildFromCompleteList<view::GraphicContainer*>(std::string("update_container"));

          if (checkChild(upgradeContainer, "Upgrade action container main container")) {
            lock();
            PhotoGallery* gallery = upgradeContainer->getChild<PhotoGallery*>(std::string("gallery"));
            if (checkChild(gallery, "Upgrade action container photo gallery")) {
              gallery->clear();
            }

            makeDeepDirty();
            unlock();
          }
        }
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[DURATION] Could not populate upgrade action container " << getName() << " with shipyard actions for planet " << planet.getName() << ":" << std::endl << e.what() << std::endl;
      }
    }

    void UpgradeActionContainer::createView() {
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
        std::make_shared<view::GridLayout>(4u, 6u, 0.0f)
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

      PhotoGalleryShPtr gallery = (m_multivalued ? createPhotoGallery(std::string("gallery"), 5u) : nullptr);

      if (title == nullptr ||
          upgradeName == nullptr ||
          picture== nullptr ||
          upgradeDescription == nullptr ||
          durationLabel == nullptr ||
          duration == nullptr ||
          withUpdateContainer == nullptr,
          (gallery == nullptr && m_multivalued))
      {
        throw GuiException(std::string("Could not allocate memory to create upgrade action container"));
      }

      withUpdateContainer->addChild(title,              0u, 0u, 4u, 1u);
      withUpdateContainer->addChild(upgradeName,        0u, 1u, 4u, 1u);
      withUpdateContainer->addChild(picture,            0u, 2u, 1u, 3u);
      withUpdateContainer->addChild(upgradeDescription, 1u, 2u, 3u, 1u);
      withUpdateContainer->addChild(durationLabel,      1u, 3u, 3u, 1u);
      withUpdateContainer->addChild(duration,           1u, 4u, 3u, 1u);
      if (m_multivalued) {
        withUpdateContainer->addChild(gallery,          0u, 5u, 4u, 1u);
      }

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
        std::make_shared<view::GridLayout>(4u, 6u, 0.0f)
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
      noUpdateContainer->addChild(noUpgrades, 0u, 1u, 4u, 5u);

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

    void UpgradeActionContainer::addToPhotoGallery(const std::vector<core::BuildingUpgradeActionShPtr>& buildings,
                                                   const bool excludeFirst,
                                                   const bool clear)
    {
      view::GraphicContainer* upgradeContainer = getChildFromCompleteList<view::GraphicContainer*>(std::string("update_container"));

      if (checkChild(upgradeContainer, "Upgrade action container main container")) {
        lock();
        // Update each information.
        PhotoGallery* gallery = upgradeContainer->getChild<PhotoGallery*>(std::string("gallery"));
        if (checkChild(gallery, "Upgrade action container photo gallery")) {
          if (clear) {
            gallery->clear();
          }

          for (unsigned index = (excludeFirst ? 1u : 0u) ; index < buildings.size() ; ++index) {
            gallery->addImage(getPictureNameFromBuilding(buildings[index]->getType()));
          }
        }

        makeDeepDirty();
        unlock();
      }
    }

    void UpgradeActionContainer::addToPhotoGallery(const std::vector<core::ResearchUpgradeActionShPtr>& researches,
                                                   const bool excludeFirst,
                                                   const bool clear)
    {
      view::GraphicContainer* upgradeContainer = getChildFromCompleteList<view::GraphicContainer*>(std::string("update_container"));

      if (checkChild(upgradeContainer, "Upgrade action container main container")) {
        lock();
        // Update each information.
        PhotoGallery* gallery = upgradeContainer->getChild<PhotoGallery*>(std::string("gallery"));
        if (checkChild(gallery, "Upgrade action container photo gallery")) {
          if (clear) {
            gallery->clear();
          }

          for (unsigned index = (excludeFirst ? 1u : 0u) ; index < researches.size() ; ++index) {
            gallery->addImage(getPictureNameFromResearch(researches[index]->getType()));
          }
        }

        makeDeepDirty();
        unlock();
      }
    }

    void UpgradeActionContainer::addToPhotoGallery(const std::vector<core::ShipUpgradeActionShPtr>& ships,
                                                   const bool excludeFirst,
                                                   const bool clear)
    {
      view::GraphicContainer* upgradeContainer = getChildFromCompleteList<view::GraphicContainer*>(std::string("update_container"));

      if (checkChild(upgradeContainer, "Upgrade action container main container")) {
        lock();
        // Update each information.
        PhotoGallery* gallery = upgradeContainer->getChild<PhotoGallery*>(std::string("gallery"));
        if (checkChild(gallery, "Upgrade action container photo gallery")) {
          if (clear) {
            gallery->clear();
          }

          for (unsigned index = (excludeFirst ? 1u : 0u) ; index < ships.size() ; ++index) {
            gallery->addImage(core::Ship::getPictureNameFromShip(ships[index]->getType(), false));
          }
        }

        makeDeepDirty();
        unlock();
      }
    }

    void UpgradeActionContainer::addToPhotoGallery(const std::vector<core::DefenseUpgradeActionShPtr>& defenses,
                                                   const bool excludeFirst,
                                                   const bool clear)
    {
      view::GraphicContainer* upgradeContainer = getChildFromCompleteList<view::GraphicContainer*>(std::string("update_container"));

      if (checkChild(upgradeContainer, "Upgrade action container main container")) {
        lock();
        // Update each information.
        PhotoGallery* gallery = upgradeContainer->getChild<PhotoGallery*>(std::string("gallery"));
        if (checkChild(gallery, "Upgrade action container photo gallery")) {
          if (clear) {
            gallery->clear();
          }

          for (unsigned index = (excludeFirst ? 1u : 0u) ; index < defenses.size() ; ++index) {
            gallery->addImage(getPictureNameFromDefense(defenses[index]->getType()));
          }
        }

        makeDeepDirty();
        unlock();
      }
    }

  }
}
