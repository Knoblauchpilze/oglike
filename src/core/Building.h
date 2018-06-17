#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include <memory>
#include <unordered_map>

#include "Resource.h"
#include "ResourceDeposit.h"

namespace ogame {
  namespace core {

    class Building
    {
      public:

        virtual ~Building();

        const unsigned& getLevel() const;

        virtual void upgrade(const std::vector<ResourceDepositShPtr>& resources) = 0;

      protected:

        Building() = delete;

        Building(const unsigned& level);

      private:

          unsigned m_level;
    };

    using BuildingShPtr = std::shared_ptr<Building>;

  }
}

#include "Building.hxx"

#endif // BUILDING_H
