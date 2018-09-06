#ifndef RESOURCESTORAGE_H
#define RESOURCESTORAGE_H

#include <memory>
#include "Resource.h"
#include "Building.h"

namespace ogame {
  namespace core {

    class ResourceStorage: public Building
    {
      public:

        ResourceStorage(const Resource& resource,
                        const float& initStorage,
                        const std::unordered_map<Resource, float>& initCost);

        virtual ~ResourceStorage();

        const std::string& getResourceName() const noexcept;

        const float getStorage() const noexcept;

      private:

        const std::string generateNameFromResource(const Resource& resource) const;

        const Building::Type getTypeFromResource(const Resource& resource) const;

      private:

        Resource m_resource;
        float m_basicStorage;
    };

    using ResourceStorageShPtr = std::shared_ptr<ResourceStorage>;

  }
}

#include "ResourceStorage.hxx"

#endif // RESOURCESTORAGE_H
