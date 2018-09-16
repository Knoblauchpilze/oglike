#ifndef DEFENSEVIEW_HXX
#define DEFENSEVIEW_HXX

#include "DefenseView.h"

namespace ogame {
  namespace gui {

    inline
    void DefenseView::populateActionData(const std::string& origin, ElementDescriptionPanel& action) const {
      // We need to extract the type of defense from the input origin name.
      try {
        const core::Defense::Type defenseType = computeDefenseFromOriginNode(origin);

        // Assign the corresponding image into the panel.
        const std::string image = core::Defense::getPictureNameFromDefense(defenseType, false);
        action.setImagePath(image);

        // Now retrieve information about this research using the active planet.
        const player::GeneralDataModel& model = getDataModel();
        const core::Account& account = model.getActiveAccount();
        const core::Planet& planet = model.getActivePlanet();
        const core::Defense& defense = planet.getDefenseData(defenseType);

        // And update the corresponding element description.
        action.populateInformationFromElement(defense, planet, account);
      }
      catch (const player::DataModelException& e) {
        std::cerr << "[DEFENSE] Could not populate action data in " << getName() << " from origin " << origin << ":" << std::endl << e.what() << std::endl;
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[DEFENSE] Could not populate action data in " << getName() << " from origin " << origin << ":" << std::endl << e.what() << std::endl;
      }
      catch (const GuiException& e) {
        std::cerr << "[DEFENSE] Could not populate action data in " << getName() << " from origin " << origin << ":" << std::endl << e.what() << std::endl;
      }
    }

    inline
    const std::string DefenseView::getDefenseCountFromType(const core::Defense::Type& type, const core::Planet& planet) const noexcept {
      return std::to_string(planet.getDefenseCount(type));
    }

    inline
    const core::Defense::Type DefenseView::computeDefenseFromOriginNode(const std::string& origin) const noexcept {
      if (origin == "missile_launcher") {
        return core::Defense::Type::MissileLauncher;
      }
      else if (origin == "light_laser") {
        return core::Defense::Type::LightLaser;
      }
      else if (origin == "heavy_laser") {
        return core::Defense::Type::HeavyLaser;
      }
      else if (origin == "gauss_cannon") {
        return core::Defense::Type::GaussCannon;
      }
      else if (origin == "ion_cannon") {
        return core::Defense::Type::IonCannon;
      }
      else if (origin == "plasma_turret") {
        return core::Defense::Type::PlasmaTurret;
      }
      else if (origin == "small_shield_dome") {
        return core::Defense::Type::SmallShieldDome;
      }
      else if (origin == "large_shield_dome") {
        return core::Defense::Type::LargeShieldDome;
      }
      else if (origin == "antiballistic_missile") {
        return core::Defense::Type::AntiballisticMissile;
      }
      else {
        return core::Defense::Type::InterplanetaryMissile;
      }
    }

  }
}

#endif // DEFENSEVIEW_HXX
