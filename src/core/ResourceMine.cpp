
#include "ResourceMine.h"

namespace ogame {
  namespace core {

    ResourceMine::ResourceMine(const Resource& resource,
                               const std::unordered_map<Resource, float>& initResources):
      Building(getTypeFromResource(resource),
               generateNameFromResource(resource),
               initResources,
               1.5f),
      m_resource(resource)
    {
      //ctor
    }

    ResourceMine::~ResourceMine()
    {
      //dtor
    }

  }
}
