#ifndef POWERPLANT_H
#define POWERPLANT_H

#include <memory>
#include "Resource.h"
#include "Building.h"

namespace ogame {
  namespace core {

    class PowerPlant: public Building
    {
      public:

        PowerPlant(const Building::Type& type,
                   const std::string& name,
                   const std::unordered_map<Resource, float>& initResources,
                   const std::unordered_map<Resource, float>& consumptionResources,
                   const float& buildingCostIncreaseFactor,
                   const float& productionIncreaseFactor);

        virtual ~PowerPlant();

        const float getEnergyProduction() const;

        const float getEnergyProductionIncrease() const;

        const float getConsumptionForResource(const Resource& resource) const;

        const float getConsumptionIncreaseForResource(const Resource& resource) const;

      private:

        const float getEnergyProductionForLevel(const unsigned& level) const;

        const float getResourceConsumptionForLevel(const Resource& resource, const unsigned& level) const;

      private:

        float m_energyProductionFactor;
        std::unordered_map<Resource, float> m_consumption;
    };

    using PowerPlantShPtr = std::shared_ptr<PowerPlant>;

  }
}

#include "PowerPlant.hxx"

#endif // POWERPLANT_H
