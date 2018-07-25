#ifndef RESOURCEHASHSPECIALIZATION_HXX
#define RESOURCEHASHSPECIALIZATION_HXX

#include <functional>
#include "Resource.h"

namespace std {

  template<>
  struct hash<ogame::core::Resource> {
    inline
    std::size_t operator()(const ogame::core::Resource& resource) const noexcept {
      std::size_t vale = hash<std::string>()(resource.getName());
      return vale;
    }
  };

}


#endif // RESOURCEHASHSPECIALIZATION_HXX
