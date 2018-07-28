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
    float BuildingUpgradeAction::computeTotalDuration() const {
      if (m_building == nullptr) {
        throw UpgradableException(std::string("Cannot compute total duration for building upgrade action, invalid null building"));
      }

      return m_building->getUpgradeTime(
        getUniverseSpeed(),
        getRoboticsLevel(),
        getNaniteLevel()
      );
    }

  }
}

#endif // BUILDINGUPGRADEACTION_HXX
