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
    const float Upgradable::getUpgradeTime() const {
      return 1.0f;
    }

  }
}

#endif // UPGRADABLE_HXX
