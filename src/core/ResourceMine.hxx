#ifndef RESOURCEMINE_HXX
#define RESOURCEMINE_HXX

#include "ResourceMine.h"
#include "BuildingException.h"

namespace ogame {
  namespace core {

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

  }
}

#endif // RESOURCEMINE_HXX
