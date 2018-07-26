#ifndef RESOURCESTORAGE_HXX
#define RESOURCESTORAGE_HXX

#include "ResourceStorage.h"
#include "BuildingException.h"

namespace ogame {
  namespace core {

    inline
    const std::string& ResourceStorage::getResourceName() const noexcept {
      return m_resource.getName();
    }

    inline
    const float& ResourceStorage::getValue() const noexcept {
      return m_value;
    }

    inline
    void ResourceStorage::decreaseValue(const float& amount) {
      if (m_value < amount) {
        const std::string errorMessage = std::string("Cannot decrease value of deposit of ") +
          std::to_string(amount) + " for resource " +
          getResourceName() + ", deposit only contains " +
          std::to_string(m_value);
        throw BuildingException(errorMessage);
      }
      m_value -= amount;
    }

    inline
    const std::string ResourceStorage::generateNameFromResource(const Resource& resource) const noexcept {
      if (resource.getName() == std::string("metal")) {
        return std::string("Metal storage");
      }
      if (resource.getName() == std::string("crystal")) {
        return std::string("Crystal storage");
      }
      if (resource.getName() == std::string("deuterium")) {
        return std::string("Deuterium tank");
      }
      throw BuildingException(std::string("Could not determine name of storage for resource ") + resource.getName());
    }

    inline
    const Building::Type ResourceStorage::getTypeFromResource(const Resource& resource) const {
      if (resource.getName() == std::string("metal")) {
        return Building::Type::MetalStorage;
      }
      if (resource.getName() == std::string("crystal")) {
        return Building::Type::CrystalStorage;
      }
      if (resource.getName() == std::string("deuterium")) {
        return Building::Type::DeuteriumStorage;
      }
      throw BuildingException(std::string("Could not determine kind of storage for resource ") + resource.getName());
    }

  }
}


#endif // RESOURCESTORAGE_HXX
