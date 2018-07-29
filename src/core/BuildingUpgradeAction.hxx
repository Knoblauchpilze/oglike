#ifndef BUILDINGUPGRADEACTION_HXX
#define BUILDINGUPGRADEACTION_HXX

#include "BuildingUpgradeAction.h"
#include "UpgradableException.h"

namespace ogame {
  namespace core {

    inline
    bool BuildingUpgradeAction::operator==(const BuildingUpgradeAction& other) const noexcept {
      return UpgradeAction::operator==(other) && m_building == other.m_building;
    }

    inline
    const std::string BuildingUpgradeAction::getName() const {
      if (m_building == nullptr) {
        throw UpgradableException(std::string("Could not retrieve name for building upgrade action, invalid null building"));
      }

      return m_building->getName();
    }

    inline
    const std::string BuildingUpgradeAction::getDescription() const {
      if (m_building == nullptr) {
        throw UpgradableException(std::string("Could not retrieve description for building upgrade action, invalid null building"));
      }

      return std::string("Improve to level ") + std::to_string(m_building->getLevel() + 1u);
    }

    inline
    const Building::Type BuildingUpgradeAction::getType() const {
      if (m_building == nullptr) {
        throw UpgradableException(std::string("Could not retrieve type for building upgrade action, invalid null building"));
      }

      return m_building->getType();
    }

    inline
    void BuildingUpgradeAction::assignTotalDuration(float& totalDuration) {
      if (m_building == nullptr) {
        throw UpgradableException(std::string("Cannot compute total duration for building upgrade action, invalid null building"));
      }

      totalDuration =  m_building->getUpgradeTime(
        getUniverseSpeed(),
        getRoboticsLevel(),
        getNaniteLevel()
      );
    }

  }
}

#endif // BUILDINGUPGRADEACTION_HXX
