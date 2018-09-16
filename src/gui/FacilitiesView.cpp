
#include "FacilitiesView.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "PictureContainer.h"
#include "ComponentFactory.h"
#include "LabelledPicture.h"

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
      LabelledPictureShPtr robotics = createLabelledPictureContainer(
        std::string("robotics_factory"),
        getPictureNameFromBuilding(core::Building::Type::RoboticsFactory),
        level0
      );
      LabelledPictureShPtr shipyard = createLabelledPictureContainer(
        std::string("shipyard"),
        getPictureNameFromBuilding(core::Building::Type::Shipyard),
        level0);
      LabelledPictureShPtr research = createLabelledPictureContainer(
        std::string("research_lab"),
        getPictureNameFromBuilding(core::Building::Type::ResearchLab),
        level0
      );
      LabelledPictureShPtr allianceDepot = createLabelledPictureContainer(
        std::string("alliance_depot"),
        getPictureNameFromBuilding(core::Building::Type::AllianceDepot),
        level0
      );
      LabelledPictureShPtr missileSilo = createLabelledPictureContainer(
        std::string("missile_silo"),
        getPictureNameFromBuilding(core::Building::Type::MissileSilo),
        level0
      );
      LabelledPictureShPtr naniteFactory = createLabelledPictureContainer(
        std::string("nanite_factory"),
        getPictureNameFromBuilding(core::Building::Type::NaniteFactory),
        level0
      );
      LabelledPictureShPtr terraformer = createLabelledPictureContainer(
        std::string("terraformer"),
        getPictureNameFromBuilding(core::Building::Type::Terraformer),
        level0
      );
      LabelledPictureShPtr spaceDock = createLabelledPictureContainer(
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
          LabelledPicture* buildingInfo = getChild<LabelledPicture*>(building.first);
          if (checkChild(buildingInfo, building.first)) {
            buildingInfo->setLabel(getDisplayForBuilding(building.second, planet));
          }
        }
      );

      makeDeepDirty();
      unlock();
    }
  }
}
