#ifndef RESOURCEDEPOSIT_HXX_INCLUDED
#define RESOURCEDEPOSIT_HXX_INCLUDED

#include "ResourceDeposit.h"
#include "BuildingException.h"

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

    inline
    void ResourceDeposit::decreaseValue(const float& amount) {
      if (m_value < amount) {
        const std::string errorMessage = std::string("Cannot decrease value of deposit of ") +
          std::to_string(amount) + " for resource " +
          getResourceName() + ", deposit only contains " +
          std::to_string(m_value);
        throw BuildingException(errorMessage);
      }
      m_value -= amount;
    }

  }
}


#endif // RESOURCEDEPOSIT_HXX_INCLUDED
