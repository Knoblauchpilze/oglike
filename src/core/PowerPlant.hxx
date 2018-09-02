#ifndef POWERPLANT_HXX
#define POWERPLANT_HXX

#include "PowerPlant.h"

namespace ogame {
  namespace core {

    inline
    const float PowerPlant::getEnergyProduction() const {
      return getEnergyProductionForLevel(getLevel());
    }

    inline
    const float PowerPlant::getEnergyProductionIncrease() const {
      return getEnergyProductionForLevel(getLevel() + 1u) - getEnergyProductionForLevel(getLevel());
    }

    inline
    const float PowerPlant::getConsumptionForResource(const Resource& resource) const {
      return getResourceConsumptionForLevel(resource, getLevel());
    }

    inline
    const float PowerPlant::getConsumptionIncreaseForResource(const Resource& resource) const {
      return getResourceConsumptionForLevel(resource, getLevel() + 1) - getResourceConsumptionForLevel(resource, getLevel());
    }

    inline
    const float PowerPlant::getEnergyProductionForLevel(const unsigned& level) const {
      return m_energyProductionFactor * level * std::pow(1.1f, 1.0f * level);
    }

    inline
    const float PowerPlant::getResourceConsumptionForLevel(const Resource& resource, const unsigned& level) const {
      const std::unordered_map<Resource, float>::const_iterator resourceConsumptionFactor = m_consumption.find(resource);
      if (resourceConsumptionFactor == m_consumption.cend()) {
        return 0.0f;
      }
      return resourceConsumptionFactor->second * level * std::pow(1.1f, 1.0f * level);
    }

  }
}

#endif // POWERPLANT_HXX
