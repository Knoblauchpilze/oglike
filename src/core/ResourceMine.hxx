#ifndef RESOURCEMINE_HXX
#define RESOURCEMINE_HXX

#include "ResourceMine.h"
#include "BuildingException.h"

namespace ogame {
  namespace core {

    inline
    const float ResourceMine::getEnergyUsed() const {
      return getEnergyForLevel(getLevel());
    }

    inline
    const float ResourceMine::getEnergyNeeded() const {
      return getEnergyForLevel(getLevel() + 1u);
    }

    inline
    const float ResourceMine::getProduction(const float& maxTemperature, const unsigned& universeSpeed) const {
      return getProductionForLevel(getLevel(), maxTemperature, universeSpeed);
    }

    inline
    const float ResourceMine::getProductionIncrease(const float& maxTemperature, const unsigned& universeSpeed) const {
      return getProductionForLevel(getLevel() + 1u, maxTemperature, universeSpeed) -
             getProductionForLevel(getLevel(), maxTemperature, universeSpeed)
      ;
    }

    inline
    const std::string ResourceMine::generateNameFromResource(const Resource& resource) const noexcept {
      if (resource.getName() == std::string("metal")) {
        return std::string("Metal mine");
      }
      if (resource.getName() == std::string("crystal")) {
        return std::string("Crystal mine");
      }
      if (resource.getName() == std::string("deuterium")) {
        return std::string("Deuterium synthesizer");
      }
      throw BuildingException(std::string("Could not determine name of mine producing resource ") + resource.getName());
    }

    inline
    const Building::Type ResourceMine::getTypeFromResource(const Resource& resource) const {
      if (resource.getName() == std::string("metal")) {
        return Building::Type::MetalMine;
      }
      if (resource.getName() == std::string("crystal")) {
        return Building::Type::CrystalMine;
      }
      if (resource.getName() == std::string("deuterium")) {
        return Building::Type::DeuteriumMine;
      }
      throw BuildingException(std::string("Could not determine kind of mine producing resource ") + resource.getName());
    }

    inline
    const float ResourceMine::getEnergyForLevel(const unsigned& level) const {
      return m_energyConsumptionFactor * level * std::pow(1.1f, 1.0f * level);
    }

    inline
    const float ResourceMine::getProductionForLevel(const unsigned& level, const float& maxTemperature, const unsigned& universeSpeed) const {
      return m_productionFactor * universeSpeed * level * std::pow(1.1f, 1.0f * level) * (m_sensibleToTemperature ? (0.64f - 0.001f * maxTemperature) : 1.0f);
    }

  }
}

#endif // RESOURCEMINE_HXX
