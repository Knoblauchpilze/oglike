
#include "FacilitiesView.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    FacilitiesView::FacilitiesView(const std::string& name, player::GeneralDataModelShPtr model):
      AbstractBuyingView(name,
                         model,
                         6u,
                         5u,
                         std::string("data/img/facilities_bg.bmp"))
    {
      createView();

      connectDataModel(player::Action::ChangePlanet);
    }

    FacilitiesView::~FacilitiesView() {}

    void FacilitiesView::createView() {
      // Create all elements.
      std::string level0 = std::to_string(0);
      BackgroundedLabelShPtr robotics = createBackgroundedLabelContainer(
        std::string("robotics_factory"),
        getPictureNameFromBuilding(core::Building::Type::RoboticsFactory),
        level0
      );
      BackgroundedLabelShPtr shipyard = createBackgroundedLabelContainer(
        std::string("shipyard"),
        getPictureNameFromBuilding(core::Building::Type::Shipyard),
        level0);
      BackgroundedLabelShPtr research = createBackgroundedLabelContainer(
        std::string("research_lab"),
        getPictureNameFromBuilding(core::Building::Type::ResearchLab),
        level0
      );
      BackgroundedLabelShPtr allianceDepot = createBackgroundedLabelContainer(
        std::string("alliance_depot"),
        getPictureNameFromBuilding(core::Building::Type::AllianceDepot),
        level0
      );
      BackgroundedLabelShPtr missileSilo = createBackgroundedLabelContainer(
        std::string("missile_silo"),
        getPictureNameFromBuilding(core::Building::Type::MissileSilo),
        level0
      );
      BackgroundedLabelShPtr naniteFactory = createBackgroundedLabelContainer(
        std::string("nanite_factory"),
        getPictureNameFromBuilding(core::Building::Type::NaniteFactory),
        level0
      );
      BackgroundedLabelShPtr terraformer = createBackgroundedLabelContainer(
        std::string("terraformer"),
        getPictureNameFromBuilding(core::Building::Type::Terraformer),
        level0
      );
      BackgroundedLabelShPtr spaceDock = createBackgroundedLabelContainer(
        std::string("space_dock"),
        getPictureNameFromBuilding(core::Building::Type::SpaceDock),
        level0
      );

      if (robotics == nullptr ||
          shipyard == nullptr ||
          research == nullptr ||
          allianceDepot == nullptr ||
          missileSilo == nullptr ||
          naniteFactory == nullptr ||
          terraformer == nullptr ||
          spaceDock == nullptr)
      {
        throw GuiException(std::string("Could not allocate memory to create facilities view"));
      }

      addChild(robotics,      0u, 2u, 1u, 1u);
      addChild(shipyard,      1u, 2u, 1u, 1u);
      addChild(research,      2u, 2u, 1u, 1u);
      addChild(allianceDepot, 3u, 2u, 1u, 1u);
      addChild(missileSilo,   4u, 2u, 1u, 1u);
      addChild(naniteFactory, 5u, 2u, 1u, 1u);
      addChild(terraformer,   0u, 3u, 1u, 1u);
      addChild(spaceDock,     1u, 3u, 1u, 1u);
    }

    void FacilitiesView::populateWithPlanetData(const core::Planet& planet) {
      lock();

      // Update each information.
      std::vector<std::pair<std::string, core::Building::Type>> buildings = {
        {std::string("robotics_factory"), core::Building::Type::RoboticsFactory},
        {std::string("shipyard"), core::Building::Type::Shipyard},
        {std::string("research_lab"), core::Building::Type::ResearchLab},

        {std::string("alliance_depot"), core::Building::Type::AllianceDepot},
        {std::string("missile_silo"), core::Building::Type::MissileSilo},
        {std::string("nanite_factory"), core::Building::Type::NaniteFactory},

        {std::string("terraformer"), core::Building::Type::Terraformer},
        {std::string("space_dock"), core::Building::Type::SpaceDock}
      };

      std::for_each(buildings.cbegin(), buildings.cend(),
        [this, &planet](const std::pair<std::string, core::Building::Type>& building) {
          BackgroundedLabel* buildingInfo = getChild<BackgroundedLabel*>(building.first);
          if (checkChild(buildingInfo, building.first)) {
            buildingInfo->setText(getDisplayForBuilding(building.second, planet));
          }
        }
      );

      makeDeepDirty();
      unlock();
    }
  }
}
