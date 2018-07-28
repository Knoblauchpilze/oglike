
#include "DefenseUpgradeAction.h"
#include "Account.h"

namespace ogame {
  namespace core {

    DefenseUpgradeAction::DefenseUpgradeAction(const Defense* defense,
                                               const Planet& planet,
                                               const Account& account):
      UpgradeAction(std::chrono::system_clock::now(),
                    UpgradeAction::Type::Defense,
                    account.getUniverseSpeed(),
                    planet.getBuildingLevel(Building::Type::Shipyard),
                    planet.getBuildingLevel(Building::Type::ResearchLab),
                    planet.getBuildingLevel(Building::Type::RoboticsFactory),
                    planet.getBuildingLevel(Building::Type::NaniteFactory)),
      m_defense(defense)
    {
      // Nothing to do here.
    }

    DefenseUpgradeAction::~DefenseUpgradeAction() {}

  }
}
