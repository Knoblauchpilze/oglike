#ifndef SHIPUPGRADEACTION_H
#define SHIPUPGRADEACTION_H

#include <memory>
#include "UpgradeAction.h"
#include "Ship.h"
#include "Planet.h"
#include "Account.h"

namespace ogame {
  namespace core {

    class Planet;
    class Account;

    class ShipUpgradeAction: public UpgradeAction
    {
      public:

        ShipUpgradeAction(const Ship* ship,
                          const Planet& planet,
                          const Account& account);

        virtual ~ShipUpgradeAction();

        bool operator==(const ShipUpgradeAction& other) const noexcept;

      protected:

        float computeTotalDuration() const override;

      private:

        const Ship* m_ship;

    };

    using ShipUpgradeActionShPtr = std::shared_ptr<ShipUpgradeAction>;

  }
}

#include "ShipUpgradeAction.hxx"

#endif // SHIPUPGRADEACTION_H
