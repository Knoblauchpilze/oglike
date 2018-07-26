#ifndef FACILITIESVIEW_HXX
#define FACILITIESVIEW_HXX

#include "FacilitiesView.h"

namespace ogame {
  namespace gui {

    inline
    void FacilitiesView::populateActionData(const std::string& origin, ElementDescriptionPanel& action) const {
      // We need to extract the type of facility from the input origin name.
      try {
        const core::Building::Type buildingType = computeBuildingFromOriginNode(origin);

        // Assign the corresponding image into the panel.
        const std::string image = getPictureNameFromBuilding(buildingType);
        action.setImagePath(image);

        // Now retrieve information about this building using the active planet.
        const player::GeneralDataModel& model = getDataModel();
        const core::Account& account = model.getActiveAccount();
        const core::Planet& planet = model.getActivePlanet();
        const core::Building& building = planet.getBuildingData(buildingType);

        // And update the corresponding element description.
        action.populateInformationFromElement(building, planet, account);
      }
      catch (const player::DataModelException& e) {
        std::cerr << "[FACILITIES] Could not populate action data in " << getName() << " from origin " << origin << ":" << std::endl << e.what() << std::endl;
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[FACILITIES] Could not populate action data in " << getName() << " from origin " << origin << ":" << std::endl << e.what() << std::endl;
      }
      catch (const GuiException& e) {
        std::cerr << "[FACILITIES] Could not populate action data in " << getName() << " from origin " << origin << ":" << std::endl << e.what() << std::endl;
      }
    }

    inline
    const std::string FacilitiesView::getDisplayForBuilding(const core::Building::Type& type, const core::Planet& planet) const noexcept {
      return std::to_string(planet.getBuildingLevel(type));
    }

    inline
    const core::Building::Type FacilitiesView::computeBuildingFromOriginNode(const std::string& origin) const noexcept {
      if (origin == "robotics_factory") {
        return core::Building::Type::RoboticsFactory;
      }
      else if (origin == "shipyard") {
        return core::Building::Type::Shipyard;
      }
      else if (origin == "research_lab") {
        return core::Building::Type::ResearchLab;
      }
      else if (origin == "alliance_depot") {
        return core::Building::Type::AllianceDepot;
      }
      else if (origin == "missile_silo") {
        return core::Building::Type::MissileSilo;
      }
      else if (origin == "nanite_factory") {
        return core::Building::Type::NaniteFactory;
      }
      else if (origin == "terraformer") {
        return core::Building::Type::Terraformer;
      }
      else {
        return core::Building::Type::SpaceDock;
      }
    }

    inline
    const std::string FacilitiesView::getPictureNameFromBuilding(const core::Building::Type& type) const noexcept {
      const std::string path("data/img/");
      std::string image;
      const std::string extension(".bmp");

      switch (type) {
        case core::Building::Type::RoboticsFactory:
          image = std::string("robotics_factory");
          break;
        case core::Building::Type::Shipyard:
          image = std::string("shipyard");
          break;
        case core::Building::Type::ResearchLab:
          image = std::string("research_laboratory");
          break;
        case core::Building::Type::AllianceDepot:
          image = std::string("alliance_depot");
          break;
        case core::Building::Type::MissileSilo:
          image = std::string("missile_silo");
          break;
        case core::Building::Type::NaniteFactory:
          image = std::string("nanite_factory");
          break;
        case core::Building::Type::Terraformer:
          image = std::string("terraformer");
          break;
        case core::Building::Type::SpaceDock:
        default:
          image = std::string("space_dock");
          break;
      }

      return path + image + extension;
    }

  }
}

#endif // FACILITIESVIEW_HXX
