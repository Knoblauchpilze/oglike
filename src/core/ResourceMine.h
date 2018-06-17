#ifndef RESOURCEMINE_H
#define RESOURCEMINE_H

#include "Resource.h"
#include "Building.h"

namespace ogame {
  namespace core {

    class ResourceMine: public Building
    {
      public:

        virtual ~ResourceMine();

        void upgrade(const std::vector<ResourceDepositShPtr>& resources) override;

      protected:

        ResourceMine(const Resource& resource, const float& factor);

      private:

        Resource m_resource;
        const float m_factor;
    };

  }
}

#endif // RESOURCEMINE_H
