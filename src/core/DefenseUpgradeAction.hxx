#ifndef DEFENSEUPGRADEACTION_HXX
#define DEFENSEUPGRADEACTION_HXX

#include "DefenseUpgradeAction.h"
#include "UpgradableException.h"

namespace ogame {
  namespace core {

    inline
    bool DefenseUpgradeAction::operator==(const DefenseUpgradeAction& other) const noexcept {
      return UpgradeAction::operator==(other) && m_defense == other.m_defense;
    }

    inline
    void DefenseUpgradeAction::assignTotalDuration(float& totalDuration) {
      if (m_defense == nullptr) {
        throw UpgradableException(std::string("Cannot compute total duration for defense upgrade action, invalid null defense"));
      }

      totalDuration = m_defense->getProductionTime(
        getUniverseSpeed(),
        getShipyardLevel(),
        getNaniteLevel()
      );
    }

  }
}

#endif // DEFENSEUPGRADEACTION_HXX