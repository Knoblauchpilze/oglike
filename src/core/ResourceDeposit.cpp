
#include "ResourceDeposit.h"

namespace ogame {
  namespace core {

    ResourceDeposit::ResourceDeposit(const Resource& resource, const float& value):
      m_resource(resource),
      m_value(value)
    {
      //ctor
    }

    ResourceDeposit::~ResourceDeposit()
    {
      //dtor
    }

  }
}
