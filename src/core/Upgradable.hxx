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
    const std::unordered_map<Resource, float>& Upgradable::getUpgradeCost() const {
      return m_upgradeCost;
    }

    inline
    void Upgradable::computeUpgradeDuration() {
    }

  }
}

#endif // UPGRADABLE_HXX
