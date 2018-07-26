
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

    void FacilitiesView::populateWithData(const core::Planet& planet, const core::Account& account) {
      lock();

      // Update each information.
      LabelledPicture* robotics = getChild<LabelledPicture*>(std::string("robotics_factory"));
      if (checkChild(robotics, "Planet robotics factory")) {
        robotics->setLabel(getDisplayForBuilding(core::Building::Type::RoboticsFactory, planet));
      }
      LabelledPicture* shipyard = getChild<LabelledPicture*>(std::string("shipyard"));
      if (checkChild(shipyard, "Planet shipyard")) {
        shipyard->setLabel(getDisplayForBuilding(core::Building::Type::Shipyard, planet));
      }
      LabelledPicture* research = getChild<LabelledPicture*>(std::string("research_lab"));
      if (checkChild(research, "Planet research laboratory")) {
        research->setLabel(getDisplayForBuilding(core::Building::Type::ResearchLab, planet));
      }

      LabelledPicture* allianceDepot = getChild<LabelledPicture*>(std::string("alliance_depot"));
      if (checkChild(allianceDepot, "Planet alliance depot")) {
        allianceDepot->setLabel(getDisplayForBuilding(core::Building::Type::AllianceDepot, planet));
      }
      LabelledPicture* missileSilo = getChild<LabelledPicture*>(std::string("missile_silo"));
      if (checkChild(missileSilo, "Planet missile silo")) {
        missileSilo->setLabel(getDisplayForBuilding(core::Building::Type::MissileSilo, planet));
      }
      LabelledPicture* naniteFactory = getChild<LabelledPicture*>(std::string("nanite_factory"));
      if (checkChild(naniteFactory, "Planet nanite factory")) {
        naniteFactory->setLabel(getDisplayForBuilding(core::Building::Type::NaniteFactory, planet));
      }

      LabelledPicture* terraformer = getChild<LabelledPicture*>(std::string("terraformer"));
      if (checkChild(terraformer, "Planet terraformer")) {
        terraformer->setLabel(getDisplayForBuilding(core::Building::Type::Terraformer, planet));
      }
      LabelledPicture* spaceDock = getChild<LabelledPicture*>(std::string("space_dock"));
      if (checkChild(spaceDock, "Planet space dock")) {
        spaceDock->setLabel(getDisplayForBuilding(core::Building::Type::SpaceDock, planet));
      }

      makeDeepDirty();
      unlock();
    }
  }
}
