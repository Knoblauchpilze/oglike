#ifndef UPGRADEACTION_HXX
#define UPGRADEACTION_HXX

#include "UpgradeAction.h"
#include "UpgradableException.h"

namespace ogame {
  namespace core {

    inline
    bool UpgradeAction::operator==(const UpgradeAction& other) const noexcept {
      return m_type == other.m_type && m_start == other.m_start && m_duration == other.m_duration;
    }

    inline
    const bool UpgradeAction::isFinished() const {
      return getRemainingTime() <= 0.0f;
    }

    inline
    const float UpgradeAction::getRemainingTime() const {
      const float elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now() -
        m_start
      ).count();

      return m_duration - elapsedTime;
    }

    inline
    float& UpgradeAction::getDuration() {
      return m_duration;
    }

    inline
    void UpgradeAction::assignTotalDuration(float& totalDuration) {
      // Nothing to do here, inheriting classes can specialize this method.
    }

    inline
    const unsigned& UpgradeAction::getUniverseSpeed() const noexcept {
      return m_universeSpeed;
    }

    inline
    const unsigned& UpgradeAction::getShipyardLevel() const noexcept {
      return m_shipyardLevel;
    }

    inline
    const unsigned& UpgradeAction::getLaboratoryLevel() const noexcept {
      return m_laboratoryLevel;
    }

    inline
    const unsigned& UpgradeAction::getRoboticsLevel() const noexcept {
      return m_roboticsLevel;
    }

    inline
    const unsigned& UpgradeAction::getNaniteLevel() const noexcept {
      return m_naniteLevel;
    }

  }
}

#endif // UPGRADEACTION_HXX
