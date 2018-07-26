
#include "ResourceStorage.h"

namespace ogame {
  namespace core {

    ResourceStorage::ResourceStorage(const Resource& resource,
                                     const float& value,
                                     const std::unordered_map<Resource, float>& initCost):
      Building(getTypeFromResource(resource),
               generateNameFromResource(resource),
               initCost,
               2.0f),
      m_resource(resource),
      m_value(value)
    {
      //ctor
    }

    ResourceStorage::~ResourceStorage()
    {
      //dtor
    }

  }
}
