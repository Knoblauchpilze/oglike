#ifndef RESOURCEDEPOSIT_HXX_INCLUDED
#define RESOURCEDEPOSIT_HXX_INCLUDED

#include "ResourceDeposit.h"

namespace ogame {
  namespace core {

    inline
    const std::string& ResourceDeposit::getResourceName() const noexcept {
      return m_resource.getName();
    }

    inline
    const float& ResourceDeposit::getValue() const noexcept {
      return m_value;
    }

    inline
    const float& ResourceDeposit::getCapacity() const noexcept {
      return m_capacity;
    }

  }
}


#endif // RESOURCEDEPOSIT_HXX_INCLUDED
