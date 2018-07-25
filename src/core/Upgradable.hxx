#ifndef UPGRADABLE_HXX
#define UPGRADABLE_HXX

#include "Upgradable.h"

namespace ogame {
  namespace core {

    inline
    const unsigned& Upgradable::getLevel() const noexcept {
      return m_level;
    }

    inline
    const float Upgradable::getUpgradeTime(const unsigned& laboratoryLevel) const {
      const std::unordered_map<Resource, float>::const_iterator metal = m_upgradeCost.find(Resource(std::string("metal")));
      const std::unordered_map<Resource, float>::const_iterator crystal = m_upgradeCost.find(Resource(std::string("crystal")));

      const float metalValue = (metal != m_upgradeCost.cend() ? metal->second : 0.0f);
      const float crystalValue = (crystal != m_upgradeCost.cend() ? crystal->second : 0.0f);

      // TODO: Account for universe speed.
      return std::max(1.0f, 3600.0f * (metalValue + crystalValue) / (1.0f * 1000.0f * (1.0f + laboratoryLevel)));
    }

    inline
    const std::unordered_map<Resource, float>& Upgradable::getUpgradeCost() const {
      return m_upgradeCost;
    }

    inline
    void Upgradable::computeUpgradeDuration() {
    }

  }
}

#endif // UPGRADABLE_HXX
