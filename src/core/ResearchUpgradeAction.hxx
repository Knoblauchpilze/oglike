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
