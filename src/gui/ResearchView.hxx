#ifndef RESEARCHVIEW_HXX
#define RESEARCHVIEW_HXX

#include "ResearchView.h"
#include "GuiException.h"
#include "DataModelException.h"
#include "AccountException.h"

namespace ogame {
  namespace gui {

    inline
    void ResearchView::populateActionData(const std::string& origin, ElementDescriptionPanel& action) const {
      // We need to extract the type of research from the input origin name.
      try {
        const core::Research::Type researchType = computeResearchFromOriginNode(origin);

        // Assign the corresponding image into the panel.
        const std::string image = core::Research::getPictureNameFromResearch(researchType, false);
        action.setImagePath(image);

        // Now retrieve information about this research using the active account.
        const player::GeneralDataModel& model = getDataModel();
        const core::Account& account = model.getActiveAccount();
        const core::Research& research = account.getResearchData(researchType);
        const core::Planet& planet = model.getActivePlanet();

        // And update the corresponding element description.
        action.populateInformationFromElement(research, planet, account);
      }
      catch (const player::DataModelException& e) {
        std::cerr << "[RESEARCH] Could not populate action data in " << getName() << " from origin " << origin << ":" << std::endl << e.what() << std::endl;
      }
      catch (const core::AccountException& e) {
        std::cerr << "[RESEARCH] Could not populate action data in " << getName() << " from origin " << origin << ":" << std::endl << e.what() << std::endl;
      }
      catch (const GuiException& e) {
        std::cerr << "[RESEARCH] Could not populate action data in " << getName() << " from origin " << origin << ":" << std::endl << e.what() << std::endl;
      }
    }

    inline
    const std::string ResearchView::getDisplayForTech(const core::Research::Type& type, const core::Account& account) const noexcept {
      return std::to_string(account.getLevelForTechnology(type));
    }

    inline
    const core::Research::Type ResearchView::computeResearchFromOriginNode(const std::string& origin) const noexcept {
      if (origin == "laser_tech") {
        return core::Research::Type::Laser;
      }
      else if (origin == "ions_tech") {
        return core::Research::Type::Ion;
      }
      else if (origin == "hyperspace_tech") {
        return core::Research::Type::Hyperspace;
      }
      else if (origin == "plasma_tech") {
        return core::Research::Type::Plasma;
      }
      else if (origin == "combustion_drive_tech") {
        return core::Research::Type::CombustionDrive;
      }
      else if (origin == "impulse_drive_tech") {
        return core::Research::Type::ImpulseDrive;
      }
      else if (origin == "hyperspace_drive_tech") {
        return core::Research::Type::HyperspaceDrive;
      }
      else if (origin == "espionage_tech") {
        return core::Research::Type::Espionage;
      }
      else if (origin == "computer_tech") {
        return core::Research::Type::Computer;
      }
      else if (origin == "astrophysics_tech") {
        return core::Research::Type::Astrophysics;
      }
      else if (origin == "irn_tech") {
        return core::Research::Type::IRN;
      }
      else if (origin == "graviton_tech") {
        return core::Research::Type::Graviton;
      }
      else if (origin == "weapon_tech") {
        return core::Research::Type::Weapon;
      }
      else if (origin == "shielding_tech") {
        return core::Research::Type::Shielding;
      }
      else if (origin == "armour_tech") {
        return core::Research::Type::Armour;
      }
      else {
        return core::Research::Type::Energy;
      }
    }

  }
}

#endif // RESEARCHVIEW_HXX
