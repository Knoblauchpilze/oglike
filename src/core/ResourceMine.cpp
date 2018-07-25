
#include "ResourceMine.h"

namespace ogame {
  namespace core {

    ResourceMine::ResourceMine(const Resource& resource, const float& factor):
      Upgradable(0u, std::unordered_map<Resource, float>()),
      m_resource(resource),
      m_factor(factor)
    {
      //ctor
    }

    ResourceMine::~ResourceMine()
    {
      //dtor
    }

    void ResourceMine::upgrade(std::vector<ResourceDepositShPtr>& resources) {
      // Remove as many resources as needed.
    }

  }
}
