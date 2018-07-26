#ifndef UPGRADABLE_H
#define UPGRADABLE_H

#include <memory>
#include <vector>
#include <unordered_map>
#include "Resource.h"
#include "ResourceDeposit.h"

namespace ogame {
  namespace core {

    class ResourceDeposit;

    class Upgradable
    {
      public:

        virtual ~Upgradable();

        const unsigned& getLevel() const noexcept;

        virtual void upgrade(std::vector<std::shared_ptr<ResourceDeposit>>& resources) = 0;

        const std::unordered_map<Resource, float>& getUpgradeCost() const;

        const bool canUpgrade(const std::vector<std::shared_ptr<ResourceDeposit>>& resources) const;

      protected:

        Upgradable() = delete;

        Upgradable(const unsigned& initLevel,
                   const std::unordered_map<Resource, float>& initCost);

      private:

        void computeUpgradeDuration();

      protected:

        unsigned m_level;
        std::unordered_map<Resource, float> m_upgradeCost;
    };

    using UpgradableShPtr = std::shared_ptr<Upgradable>;

  }
}

#include "Upgradable.hxx"

#endif // UPGRADABLE_H
