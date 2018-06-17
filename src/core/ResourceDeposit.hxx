#ifndef RESOURCEDEPOSIT_HXX_INCLUDED
#define RESOURCEDEPOSIT_HXX_INCLUDED

#include "ResourceDeposit.h"

namespace ogame {
  namespace core {

    inline
    const float& ResourceDeposit::getValue() const {
      return m_value;
    }

    inline
    const float& ResourceDeposit::getCapacity() const {
      return m_capacity;
    }

  }
}


#endif // RESOURCEDEPOSIT_HXX_INCLUDED
