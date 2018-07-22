#ifndef RESOURCEMINE_H
#define RESOURCEMINE_H

#include "Resource.h"
#include "Upgradable.h"

namespace ogame {
  namespace core {

    class ResourceMine: public Upgradable
    {
      public:

        ResourceMine(const Resource& resource, const float& factor);

        virtual ~ResourceMine();

        void upgrade(const std::vector<ResourceDepositShPtr>& resources) override;

      private:

        Resource m_resource;
        const float m_factor;
    };

  }
}

#endif // RESOURCEMINE_H
