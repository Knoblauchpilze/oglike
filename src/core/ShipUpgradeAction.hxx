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
    const std::string ShipUpgradeAction::getName() const {
      if (m_ship == nullptr) {
        throw UpgradableException(std::string("Could not retrieve name for ship upgrade action, invalid null ship"));
      }

      return m_ship->getName();
    }

    inline
    const std::string ShipUpgradeAction::getDescription() const {
      return std::string("Assembling ship");
    }

    inline
    const Ship::Type ShipUpgradeAction::getType() const {
      if (m_ship == nullptr) {
        throw UpgradableException(std::string("Could not retrieve type for ship upgrade action, invalid null ship"));
      }

      return m_ship->getType();
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
