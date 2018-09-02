
#include "Upgradable.h"

namespace ogame {
  namespace core {

    Upgradable::Upgradable(const unsigned& initLevel,
                           const std::unordered_map<Resource, float>& initCost):
      m_level(initLevel),
      m_upgradeCost(initCost)
    {
      // Nothing to do here.
    }

    Upgradable::~Upgradable() {}

    const bool Upgradable::canUpgrade(const std::vector<ResourceDepositShPtr>& resources) const {
      // Check whether each resource exists in sufficient quantitty in the input vector.
      std::unordered_map<Resource, float>::const_iterator neededResource = m_upgradeCost.cbegin();
      while (neededResource != m_upgradeCost.cend()) {
        // Find this resource in the input vector.
        unsigned indexDeposit = 0u;
        while (indexDeposit < resources.size() && resources[indexDeposit]->getResourceName() != neededResource->first.getName()) {
          ++indexDeposit;
        }

        // We could not find this resource, which can obviously not exist in sufficient quantity.
        if (indexDeposit >= resources.size()) {
          return false;
        }

        // This resource does exist but not in sufficient quantity.
        if (resources[indexDeposit]->getValue() < neededResource->second) {
          return false;
        }

        ++neededResource;
      }

      return true;
    }

  }
}
