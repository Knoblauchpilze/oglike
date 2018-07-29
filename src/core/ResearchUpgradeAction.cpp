
#include "ResearchUpgradeAction.h"
#include "Account.h"

namespace ogame {
  namespace core {

    ResearchUpgradeAction::ResearchUpgradeAction(const Research* research,
                                                 const Planet& planet,
                                                 const Account& account):
      UpgradeAction(std::chrono::system_clock::now(),
                    UpgradeAction::Type::Research,
                    account.getUniverseSpeed(),
                    planet.getBuildingLevel(Building::Type::Shipyard),
                    planet.getBuildingLevel(Building::Type::ResearchLab),
                    planet.getBuildingLevel(Building::Type::RoboticsFactory),
                    planet.getBuildingLevel(Building::Type::NaniteFactory)),
      m_research(research)
    {
      assignTotalDuration(getDuration());
    }

    ResearchUpgradeAction::~ResearchUpgradeAction() {}

  }
}
