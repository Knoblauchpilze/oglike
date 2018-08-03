
#include "AbstractUpgradable.h"
#include "UpgradableException.h"

#include <iostream>

namespace ogame {
  namespace core {

    AbstractUpgradable::AbstractUpgradable(const unsigned& initLevel,
                                           const std::unordered_map<Resource, float>& initCost,
                                           const float& factor):
      Upgradable(initLevel, initCost),
      m_factor(factor)
    {
      // Nothing to do here.
    }

    AbstractUpgradable::~AbstractUpgradable() {}

    void AbstractUpgradable::upgrade() {
      ++m_level;
      updateUpgradeCost();
    }

    void AbstractUpgradable::updateUpgradeCost() {
      // Multiply all the quantities by the internal factor.
      std::unordered_map<Resource, float>::iterator neededResource = m_upgradeCost.begin();
      while (neededResource != m_upgradeCost.end()) {
        neededResource->second *= m_factor;
        ++neededResource;
      }
    }

  }
}
