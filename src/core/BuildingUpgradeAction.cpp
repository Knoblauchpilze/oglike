
#include "BuildingUpgradeAction.h"
#include "Account.h"

namespace ogame {
  namespace core {

    BuildingUpgradeAction::BuildingUpgradeAction(const Building* building,
                                                 const Planet& planet,
                                                 const Account& account):
      UpgradeAction(std::chrono::system_clock::now(),
                    UpgradeAction::Type::Building,
                    account.getUniverseSpeed(),
                    planet.getBuildingLevel(Building::Type::Shipyard),
                    planet.getBuildingLevel(Building::Type::ResearchLab),
                    planet.getBuildingLevel(Building::Type::RoboticsFactory),
                    planet.getBuildingLevel(Building::Type::NaniteFactory)),
      m_building(building)
    {
      assignTotalDuration(getDuration());
    }

    BuildingUpgradeAction::~BuildingUpgradeAction() {}

  }
}
