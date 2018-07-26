#ifndef BUILDING_HXX
#define BUILDING_HXX

#include "Building.h"
#include <cmath>

namespace ogame {
  namespace core {

    inline
    const Building::Type& Building::getType() const noexcept {
      return m_type;
    }

    inline
    const std::string& Building::getName() const noexcept {
      return m_name;
    }

    inline
    const float Building::getUpgradeTime(const unsigned& universeSpeed,
                                         const unsigned& roboticsLevel,
                                         const unsigned& naniteLevel) const
    {
      const std::unordered_map<Resource, float>::const_iterator metal = m_upgradeCost.find(Resource(std::string("metal")));
      const std::unordered_map<Resource, float>::const_iterator crystal = m_upgradeCost.find(Resource(std::string("crystal")));

      const float metalValue = (metal != m_upgradeCost.cend() ? metal->second : 0.0f);
      const float crystalValue = (crystal != m_upgradeCost.cend() ? crystal->second : 0.0f);

      return std::max(1.0f, 3600.0f * (metalValue + crystalValue) / (universeSpeed * 2500.0f * (1.0f + roboticsLevel) * std::pow(2.0f, 1.0f * naniteLevel)));
    }

    template <typename ChildClass>
    inline
    const ChildClass* Building::asType() const {
      return dynamic_cast<const ChildClass*>(this);
    }

  }
}

#endif // BUILDING_HXX
