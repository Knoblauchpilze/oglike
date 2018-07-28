#ifndef RESEARCHUPGRADEACTION_H
#define RESEARCHUPGRADEACTION_H

#include <memory>
#include "UpgradeAction.h"
#include "Research.h"

namespace ogame {
  namespace core {

    class Planet;
    class Account;

    class ResearchUpgradeAction: public UpgradeAction
    {
      public:

        ResearchUpgradeAction(const Research* research,
                              const Planet& planet,
                              const Account& account);

        virtual ~ResearchUpgradeAction();

        bool operator==(const ResearchUpgradeAction& other) const noexcept;

      protected:

        void assignTotalDuration(float& totalDuration) override;

      private:

        const Research* m_research;

    };

    using ResearchUpgradeActionShPtr = std::shared_ptr<ResearchUpgradeAction>;

  }
}

#include "ResearchUpgradeAction.hxx"

#endif // RESEARCHUPGRADEACTION_H
