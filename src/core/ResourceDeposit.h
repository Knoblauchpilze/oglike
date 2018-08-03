#ifndef RESOURCEDEPOSIT_H
#define RESOURCEDEPOSIT_H

#include <memory>
#include "Resource.h"

namespace ogame {
  namespace core {

    class ResourceDeposit
    {
      public:

        ResourceDeposit(const Resource& resource, const float& value);

        virtual ~ResourceDeposit();

        const std::string& getResourceName() const noexcept;

        const float& getValue() const noexcept;

        void decreaseValue(const float& amount);

        void increase(const float& amount);

        const bool isOfResource(const Resource& resource) const noexcept;

      protected:

      private:

        Resource m_resource;
        float m_value;
    };

    using ResourceDepositShPtr = std::shared_ptr<ResourceDeposit>;

  }
}

#include "ResourceDeposit.hxx"

#endif // RESOURCEDEPOSIT_H
