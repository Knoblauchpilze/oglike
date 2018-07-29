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
    const std::string DefenseUpgradeAction::getName() const {
      if (m_defense == nullptr) {
        throw UpgradableException(std::string("Could not retrieve name for defense upgrade action, invalid null defense"));
      }

      return m_defense->getName();
    }

    inline
    const std::string DefenseUpgradeAction::getDescription() const {
      return std::string("Assembling defense");
    }

    inline
    const Defense::Type DefenseUpgradeAction::getType() const {
      if (m_defense == nullptr) {
        throw UpgradableException(std::string("Could not retrieve type for defense upgrade action, invalid null defense"));
      }

      return m_defense->getType();
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
