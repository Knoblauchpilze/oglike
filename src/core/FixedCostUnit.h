#ifndef FIXEDCOSTUNIT_H
#define FIXEDCOSTUNIT_H

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include "Resource.h"
#include "ResourceDeposit.h"

namespace ogame {
  namespace core {

    class FixedCostUnit
    {
      public:

        virtual ~FixedCostUnit();

        const std::string& getName() const noexcept;

        // Time in seconds.
        const float getProductionTime(const unsigned& universeSpeed,
                                      const unsigned& shipyardLevel,
                                      const unsigned& naniteLevel) const;

        const std::unordered_map<Resource, float>& getCost() const;

        const bool canBuy(const std::vector<ResourceDepositShPtr>& resources) const;

      protected:

        FixedCostUnit() = delete;

        FixedCostUnit(const std::string& name,
                      const std::unordered_map<Resource, float>& cost);

      private:

        std::string m_name;
        std::unordered_map<Resource, float> m_cost;
    };

    using FixedCostUnitShPtr = std::shared_ptr<FixedCostUnit>;

  }
}

#include "FixedCostUnit.hxx"

#endif // FIXEDCOSTUNIT_H
