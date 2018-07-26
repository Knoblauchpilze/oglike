#ifndef RESOURCEMINE_H
#define RESOURCEMINE_H

#include <memory>
#include "Resource.h"
#include "Building.h"

namespace ogame {
  namespace core {

    class ResourceMine: public Building
    {
      public:

        ResourceMine(const Resource& resource,
                     const std::unordered_map<Resource, float>& initResources,
                     const float& energyConsumptionFactor);

        virtual ~ResourceMine();

        const float getEnergyUsed() const;

        const float getEnergyNeeded() const;

      private:

        const std::string generateNameFromResource(const Resource& resource) const noexcept;

        const Building::Type getTypeFromResource(const Resource& resource) const;

        const float getEnergyForLevel(const unsigned& level) const;

      private:

        Resource m_resource;
        float m_energyConsumptionFactor;
    };

    using ResourceMineShPtr = std::shared_ptr<ResourceMine>;

  }
}

#include "ResourceMine.hxx"

#endif // RESOURCEMINE_H
