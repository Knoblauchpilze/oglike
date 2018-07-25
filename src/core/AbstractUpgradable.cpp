
#include "AbstractUpgradable.h"
#include "UpgradableException.h"

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

    void AbstractUpgradable::upgrade(std::vector<ResourceDepositShPtr>& resources) {
      // Assume we can upgrade this element.
      std::unordered_map<Resource, float>::const_iterator neededResource = m_upgradeCost.cbegin();
      while (neededResource != m_upgradeCost.cend()) {
        // Find this resource in the input vector.
        unsigned indexDeposit = 0u;
        while (indexDeposit < resources.size() && resources[indexDeposit]->getResourceName() != neededResource->first.getName()) {
          ++indexDeposit;
        }

        // We could not find this resource, which can obviously not exist in sufficient quantity.
        if (indexDeposit >= resources.size()) {
          const std::string errorMessage = std::string("Cannot upgrade to level ") +
            std::to_string(getLevel() + 1u) + ", needing " +
            std::to_string(neededResource->second) + " of " +
            neededResource->first.getName() + " but no such resource exist in deposit ";
          throw UpgradableException(errorMessage);
        }

        // This resource does exist but not in sufficient quantity.
        if (resources[indexDeposit]->getValue() < neededResource->second) {
          const std::string errorMessage = std::string("Cannot upgrade to level ") +
            std::to_string(getLevel() + 1u) + ", needing " +
            std::to_string(neededResource->second) + " of " +
            neededResource->first.getName() + " but only " +
            std::to_string(resources[indexDeposit]->getValue()) + " available in deposit";
          throw UpgradableException(errorMessage);
        }

        // Remove resources from the deposit
        resources[indexDeposit]->decreaseValue(neededResource->second);

        // Move on to the next resource.
        ++neededResource;
      }

      // Upgrade the cost.
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
