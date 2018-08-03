
#include "FixedCostUnit.h"

namespace ogame {
  namespace core {

    FixedCostUnit::FixedCostUnit(const std::string& name,
                                 const std::unordered_map<Resource, float>& cost):
      m_name(name),
      m_count(0u),
      m_cost(cost)
    {
      // Nothing to do here.
    }

    FixedCostUnit::~FixedCostUnit() {}

    const bool FixedCostUnit::canBuy(const std::vector<ResourceDepositShPtr>& resources) const {
      // Check whether each resource exists in sufficient quantitty in the input vector.
      std::unordered_map<Resource, float>::const_iterator neededResource = m_cost.cbegin();
      while (neededResource != m_cost.cend()) {
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
