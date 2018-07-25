#ifndef RESOURCE_HXX_INCLUDED
#define RESOURCE_HXX_INCLUDED

#include "Resource.h"

namespace ogame {
  namespace core {

    inline
    bool Resource::operator==(const Resource& other) const noexcept {
      return m_name == other.m_name;
    }

    inline
    const std::string& Resource::getName() const {
      return m_name;
    }

  }
}


#endif // RESOURCE_HXX_INCLUDED
