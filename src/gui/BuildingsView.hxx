#ifndef BUILDINGSVIEW_HXX
#define BUILDINGSVIEW_HXX

#include "BuildingsView.h"

namespace ogame {
  namespace gui {

    inline
    void BuildingsView::populateActionData(const std::string& origin, ElementDescriptionPanel& action) const {
      // We need to extract the type of building from the input origin name.
      try {
        const core::Building::Type buildingType = computeBuildingFromOriginNode(origin);

        // Assign the corresponding image into the panel.
        const std::string image = core::Building::getPictureNameFromBuilding(buildingType, false);
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
        std::cerr << "[BUILDINGS] Could not populate action data in " << getName() << " from origin " << origin << ":" << std::endl << e.what() << std::endl;
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[BUILDINGS] Could not populate action data in " << getName() << " from origin " << origin << ":" << std::endl << e.what() << std::endl;
      }
      catch (const GuiException& e) {
        std::cerr << "[BUILDINGS] Could not populate action data in " << getName() << " from origin " << origin << ":" << std::endl << e.what() << std::endl;
      }
    }

    inline
    const std::string BuildingsView::getDisplayForBuilding(const core::Building::Type& type, const core::Planet& planet) const noexcept {
      return std::to_string(planet.getBuildingLevel(type));
    }

    inline
    const core::Building::Type BuildingsView::computeBuildingFromOriginNode(const std::string& origin) const noexcept {
      if (origin == "metal_mine") {
        return core::Building::Type::MetalMine;
      }
      else if (origin == "crystal_mine") {
        return core::Building::Type::CrystalMine;
      }
      else if (origin == "deut_synthesizer") {
        return core::Building::Type::DeuteriumMine;
      }
      else if (origin == "solar_plant") {
        return core::Building::Type::SolarPlant;
      }
      else if (origin == "fusion_plant") {
        return core::Building::Type::FusionPlant;
      }
      else if (origin == "metal_storage") {
        return core::Building::Type::MetalStorage;
      }
      else if (origin == "crystal_storage") {
        return core::Building::Type::CrystalStorage;
      }
      else if (origin == "deut_tank") {
        return core::Building::Type::DeuteriumStorage;
      }
      else {
        // TODO: Update
        return core::Building::Type::SolarPlant;
      }
    }

  }
}

#endif // BUILDINGSVIEW_HXX
