
#include "ResourceMine.h"

namespace ogame {
  namespace core {

    ResourceMine::ResourceMine(const Resource& resource,
                               const std::unordered_map<Resource, float>& initResources,
                               const float& energyConsumptionFactor,
                               const float& productionFactor,
                               const bool sensibleToTemperature):
      Building(getTypeFromResource(resource),
               generateNameFromResource(resource),
               initResources,
               1.5f),
      m_resource(resource),
      m_energyConsumptionFactor(energyConsumptionFactor),
      m_productionFactor(productionFactor),
      m_sensibleToTemperature(sensibleToTemperature)
    {
      //ctor
    }

    ResourceMine::~ResourceMine()
    {
      //dtor
    }

  }
}
