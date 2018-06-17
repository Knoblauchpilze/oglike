
#include "ResourceDeposit.h"

namespace ogame {
  namespace core {

    ResourceDeposit::ResourceDeposit(const Resource& resource, const float& value, const float& capacity):
      m_resource(resource),
      m_value(value),
      m_capacity(capacity)
    {
      //ctor
    }

    ResourceDeposit::~ResourceDeposit()
    {
      //dtor
    }

  }
}
