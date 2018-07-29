#ifndef BUILDINGUPGRADEACTION_H
#define BUILDINGUPGRADEACTION_H

#include <memory>
#include "UpgradeAction.h"
#include "Building.h"

namespace ogame {
  namespace core {

    class Planet;
    class Account;

    class BuildingUpgradeAction: public UpgradeAction
    {
      public:

        BuildingUpgradeAction(const Building* building,
                              const Planet& planet,
                              const Account& account);

        virtual ~BuildingUpgradeAction();

        bool operator==(const BuildingUpgradeAction& other) const noexcept;

        const std::string getName() const override;

        const std::string getDescription() const override;

        const Building::Type getType() const;

      protected:

        void assignTotalDuration(float& totalDuration) override;

      private:

        const Building* m_building;

    };

    using BuildingUpgradeActionShPtr = std::shared_ptr<BuildingUpgradeAction>;

  }
}

#include "BuildingUpgradeAction.hxx"

#endif // BUILDINGUPGRADEACTION_H
