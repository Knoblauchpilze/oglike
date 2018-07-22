#ifndef UPGRADABLE_H
#define UPGRADABLE_H

#include <memory>
#include <vector>
#include "ResourceDeposit.h"

namespace ogame {
  namespace core {

    class Upgradable
    {
      public:

        virtual ~Upgradable();

        const unsigned& getLevel() const noexcept;

        virtual void upgrade(const std::vector<ResourceDepositShPtr>& resources) = 0;

        // Time in seconds.
        const float getUpgradeTime() const;

      protected:

        Upgradable() = delete;

        Upgradable(const unsigned& initLevel);

      private:

        unsigned m_level;
    };

    using UpgradableShPtr = std::shared_ptr<Upgradable>;

  }
}

#include "Upgradable.hxx"

#endif // UPGRADABLE_H
