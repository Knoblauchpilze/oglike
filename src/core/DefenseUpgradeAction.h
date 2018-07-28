#ifndef DEFENSEUPGRADEACTION_H
#define DEFENSEUPGRADEACTION_H

#include <memory>
#include "UpgradeAction.h"
#include "Defense.h"

namespace ogame {
  namespace core {

    class Planet;
    class Account;

    class DefenseUpgradeAction: public UpgradeAction
    {
      public:

        DefenseUpgradeAction(const Defense* defense,
                             const Planet& planet,
                             const Account& account);

        virtual ~DefenseUpgradeAction();

        bool operator==(const DefenseUpgradeAction& other) const noexcept;

      protected:

        void assignTotalDuration(float& totalDuration) override;

      private:

        const Defense* m_defense;

    };

    using DefenseUpgradeActionShPtr = std::shared_ptr<DefenseUpgradeAction>;

  }
}

#include "DefenseUpgradeAction.hxx"

#endif // DEFENSEUPGRADEACTION_H
