#ifndef RESOURCEDEPOSIT_H
#define RESOURCEDEPOSIT_H

#include <memory>

#include "Resource.h"

namespace ogame {
  namespace core {

    class ResourceDeposit
    {
      public:

        ResourceDeposit(const Resource& resource, const float& value, const float& capacity);

        virtual ~ResourceDeposit();

        const std::string& getResourceName() const noexcept;

        const float& getValue() const noexcept;

        const float& getCapacity() const noexcept;

      protected:

      private:

        Resource m_resource;
        float m_value;
        float m_capacity;
    };

    using ResourceDepositShPtr = std::shared_ptr<ResourceDeposit>;

  }
}

#include "ResourceDeposit.hxx"

#endif // RESOURCEDEPOSIT_H
