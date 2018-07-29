
#include "UpgradeActionContainer.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "PictureContainer.h"
#include "ComponentFactory.h"

namespace ogame {
  namespace gui {

    UpgradeActionContainer::UpgradeActionContainer(const std::string& name):
      view::GraphicContainer(name,
                             view::utils::Area())
    {
      createView();
    }

    UpgradeActionContainer::~UpgradeActionContainer() {}

    void UpgradeActionContainer::populateWithBuildingData(const core::Planet& planet) {
      lock();

      // Update each information.
      try {

        // Retrieve the building upgrades action and display the first one.
        const std::vector<core::BuildingUpgradeActionShPtr>& upgrades = planet.getBuildingUpgrades();
        bool hasBuildingUpgrade = !upgrades.empty();
        const core::BuildingUpgradeAction* upgrade = nullptr;
        if (hasBuildingUpgrade) {
          upgrade = upgrades[0u].get();
        }


        LabelContainer* title = getChild<LabelContainer*>(std::string("title"));
        if (checkChild(title, "Upgrade action container title")) {
          title->setText("Buildings");
        }

        LabelContainer* upgradeName = getChild<LabelContainer*>(std::string("upgrade_name"));
        if (checkChild(upgradeName, "Upgrade action container upgrade name")) {
          upgradeName->setText(hasBuildingUpgrade ?
            upgrade->getName() :
            std::string("")
          );
        }

        PictureContainer* picture = getChild<PictureContainer*>(std::string("picture"));
        if (checkChild(picture, "Upgrade action container picture")) {
          if (hasBuildingUpgrade) {
            picture->setImagePath(getPictureNameFromBuilding(upgrade->getType()));
          }
          else {
            picture->clear();
          }
        }

        LabelContainer* upgradeDesc = getChild<LabelContainer*>(std::string("upgrade_desc"));
        if (checkChild(upgradeDesc, "Upgrade action container description")) {
          upgradeDesc->setText(hasBuildingUpgrade ?
            upgrade->getDescription() :
            std::string("")
          );
        }

        LabelContainer* duration = getChild<LabelContainer*>(std::string("duration_value"));
        if (checkChild(duration, "Upgrade action container duration")) {
          duration->setText("tata");
          duration->setText(hasBuildingUpgrade ?
            (upgrade->isFinished() ?
              std::string("done") :
              computeDisplayTime(upgrade->getRemainingTime())
            ) :
            std::string("")
          );
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
        LabelContainer::Alignment::Center
      );

      LabelContainerShPtr upgradeName = createLabel(
        std::string("upgrade_name"),
        std::string("Default upgrade name"),
        SDL_Color{255, 255, 255, SDL_ALPHA_OPAQUE}
      );

      PictureContainerShPtr picture = ComponentFactory::createPicturePanel(std::string("picture"), std::string("data/img/solar_plant.bmp"));

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
        SDL_Color{255, 255, 255, SDL_ALPHA_OPAQUE}
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

  }
}
