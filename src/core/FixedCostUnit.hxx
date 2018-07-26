#ifndef FIXEDCOSTUNIT_HXX
#define FIXEDCOSTUNIT_HXX

#include "FixedCostUnit.h"
#include <cmath>

namespace ogame {
  namespace core {

    inline
    const std::string& FixedCostUnit::getName() const noexcept {
      return m_name;
    }

    inline
    const float FixedCostUnit::getProductionTime(const unsigned& universeSpeed,
                                                 const unsigned& shipyardLevel,
                                                 const unsigned& naniteLevel) const
    {
      const std::unordered_map<Resource, float>::const_iterator metal = m_cost.find(Resource(std::string("metal")));
      const std::unordered_map<Resource, float>::const_iterator crystal = m_cost.find(Resource(std::string("crystal")));

      const float metalValue = (metal != m_cost.cend() ? metal->second : 0.0f);
      const float crystalValue = (crystal != m_cost.cend() ? crystal->second : 0.0f);

      return std::max(1.0f, 3600.0f * (metalValue + crystalValue) / (universeSpeed * 2500.0f * (1.0f + shipyardLevel) * std::pow(2.0f, 1.0f * naniteLevel)));
    }

    inline
    const std::unordered_map<Resource, float>& FixedCostUnit::getCost() const {
      return m_cost;
    }

  }
}

#endif // FIXEDCOSTUNIT_HXX
