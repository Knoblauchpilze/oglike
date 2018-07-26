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
                     const std::unordered_map<Resource, float>& initResources);

        virtual ~ResourceMine();

      private:

        const std::string generateNameFromResource(const Resource& resource) const noexcept;

        const Building::Type getTypeFromResource(const Resource& resource) const;

      private:

        Resource m_resource;
    };

    using ResourceMineShPtr = std::shared_ptr<ResourceMine>;

  }
}

#include "ResourceMine.hxx"

#endif // RESOURCEMINE_H
