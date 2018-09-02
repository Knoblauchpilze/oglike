
#include "PowerPlant.h"

namespace ogame {
  namespace core {

    PowerPlant::PowerPlant(const Building::Type& type,
                           const std::string& name,
                           const std::unordered_map<Resource, float>& initResources,
                           const std::unordered_map<Resource, float>& consumptionResources,
                           const float& buildingCostIncreaseFactor,
                           const float& productionIncreaseFactor):
      Building(type,
               name,
               initResources,
               buildingCostIncreaseFactor),
      m_energyProductionFactor(productionIncreaseFactor),
      m_consumption(consumptionResources)
    {
      //ctor
    }

    PowerPlant::~PowerPlant()
    {
      //dtor
    }

  }
}
