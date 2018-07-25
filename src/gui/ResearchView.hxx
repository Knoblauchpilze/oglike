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
        const std::string image = getPictureNameFromResearch(researchType);
        action.setImagePath(image);

        // Now retrieve information about this research using the active account.
        const player::GeneralDataModel& model = getDataModel();
        const core::Account& account = model.getActiveAccount();
        const core::Research& research = account.getResearchData(researchType);
        const core::Planet& planet = model.getActivePlanet();

        // And update the corresponding element description.
        action.populateInformationFromElement(research, planet);
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

    inline
    const std::string ResearchView::getPictureNameFromResearch(const core::Research::Type& type) const noexcept {
      const std::string path("data/img/");
      std::string image;
      const std::string extension("_tech.bmp");

      switch (type) {
        case core::Research::Type::Laser:
          image = std::string("laser");
          break;
        case core::Research::Type::Ion:
          image = std::string("ions");
          break;
        case core::Research::Type::Hyperspace:
          image = std::string("hyperspace");
          break;
        case core::Research::Type::Plasma:
          image = std::string("plasma");
          break;
        case core::Research::Type::CombustionDrive:
          image = std::string("combustion_drive");
          break;
        case core::Research::Type::ImpulseDrive:
          image = std::string("impulse_drive");
          break;
        case core::Research::Type::HyperspaceDrive:
          image = std::string("hyperspace_drive");
          break;
        case core::Research::Type::Espionage:
          image = std::string("espionage");
          break;
        case core::Research::Type::Computer:
          image = std::string("computer");
          break;
        case core::Research::Type::Astrophysics:
          image = std::string("astrophysics");
          break;
        case core::Research::Type::IRN:
          image = std::string("intergalactic_research_network");
          break;
        case core::Research::Type::Graviton:
          image = std::string("graviton");
          break;
        case core::Research::Type::Weapon:
          image = std::string("weapon");
          break;
        case core::Research::Type::Shielding:
          image = std::string("shielding");
          break;
        case core::Research::Type::Armour:
          image = std::string("armour");
          break;
        case core::Research::Type::Energy:
        default:
          image = std::string("energy");
          break;
      }

      return path + image + extension;
    }

  }
}

#endif // RESEARCHVIEW_HXX
