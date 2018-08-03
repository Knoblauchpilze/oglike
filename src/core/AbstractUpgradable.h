#ifndef ABSTRACTUPGRADABLE_H
#define ABSTRACTUPGRADABLE_H

#include <memory>
#include <vector>
#include <unordered_map>
#include "Upgradable.h"

namespace ogame {
  namespace core {

    class AbstractUpgradable: public Upgradable
    {
      public:

        virtual ~AbstractUpgradable();

        void upgrade() override;

      protected:

        AbstractUpgradable() = delete;

        AbstractUpgradable(const unsigned& initLevel,
                           const std::unordered_map<Resource, float>& initCost,
                           const float& factor);

      private:

        void updateUpgradeCost();

      private:

        float m_factor;
    };

    using AbstractUpgradableShPtr = std::shared_ptr<AbstractUpgradable>;

  }
}

#endif // ABSTRACTUPGRADABLE_H
