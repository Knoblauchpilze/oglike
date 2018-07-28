#ifndef SHIPUPGRADEACTION_HXX
#define SHIPUPGRADEACTION_HXX

#include "ShipUpgradeAction.h"
#include "UpgradableException.h"

namespace ogame {
  namespace core {

    inline
    bool ShipUpgradeAction::operator==(const ShipUpgradeAction& other) const noexcept {
      return UpgradeAction::operator==(other) && m_ship == other.m_ship;
    }

    inline
    void ShipUpgradeAction::assignTotalDuration(float& totalDuration) {
      if (m_ship == nullptr) {
        throw UpgradableException(std::string("Cannot compute total duration for ship upgrade action, invalid null ship"));
      }

      totalDuration = m_ship->getProductionTime(
        getUniverseSpeed(),
        getShipyardLevel(),
        getNaniteLevel()
      );
    }

  }
}

#endif // SHIPUPGRADEACTION_HXX
