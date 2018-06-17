#ifndef RESOURCE_HXX_INCLUDED
#define RESOURCE_HXX_INCLUDED

#include "Resource.h"

namespace ogame {
  namespace core {

    inline
    const std::string& Resource::getName() const {
      return m_name;
    }

  }
}

namespace std {

  template <> struct hash<ogame::core::Resource> {
    size_t operator()(const ogame::core::Resource& res) const {
      return hash<std::string>()(res.getName());
    }
  };
}


#endif // RESOURCE_HXX_INCLUDED
