#ifndef RESEARCHUPGRADEACTION_HXX
#define RESEARCHUPGRADEACTION_HXX

#include "ResearchUpgradeAction.h"
#include "UpgradableException.h"

namespace ogame {
  namespace core {

    inline
    bool ResearchUpgradeAction::operator==(const ResearchUpgradeAction& other) const noexcept {
      return UpgradeAction::operator==(other) && m_research == other.m_research;
    }

    inline
    const std::string ResearchUpgradeAction::getName() const {
      if (m_research == nullptr) {
        throw UpgradableException(std::string("Could not retrieve name for research upgrade action, invalid null research"));
      }

      return m_research->getName();
    }

    inline
    const std::string ResearchUpgradeAction::getDescription() const {
      if (m_research == nullptr) {
        throw UpgradableException(std::string("Could not retrieve description for research upgrade action, invalid null research"));
      }

      return std::string("Research to level ") + std::to_string(m_research->getLevel() + 1u);
    }

    inline
    const Research::Type ResearchUpgradeAction::getType() const {
      if (m_research == nullptr) {
        throw UpgradableException(std::string("Could not retrieve type for research upgrade action, invalid null research"));
      }

      return m_research->getType();
    }

    inline
    void ResearchUpgradeAction::assignTotalDuration(float& totalDuration) {
      if (m_research == nullptr) {
        throw UpgradableException(std::string("Cannot compute total duration for research upgrade action, invalid null research"));
      }

      totalDuration = m_research->getUpgradeTime(
        getUniverseSpeed(),
        getLaboratoryLevel()
      );
    }

  }
}

#endif // RESEARCHUPGRADEACTION_HXX
