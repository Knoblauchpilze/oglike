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
                        const float& value,
                        const std::unordered_map<Resource, float>& initCost);

        virtual ~ResourceStorage();

        const std::string& getResourceName() const noexcept;

        const float& getValue() const noexcept;

        void decreaseValue(const float& amount);

      private:

        const std::string generateNameFromResource(const Resource& resource) const noexcept;

        const Building::Type getTypeFromResource(const Resource& resource) const;

      private:

        Resource m_resource;
        float m_value;
    };

    using ResourceStorageShPtr = std::shared_ptr<ResourceStorage>;

  }
}

#include "ResourceStorage.hxx"

#endif // RESOURCESTORAGE_H
