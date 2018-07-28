
#include "ShipUpgradeAction.h"

namespace ogame {
  namespace core {

    ShipUpgradeAction::ShipUpgradeAction(const Ship* ship,
                                         const Planet& planet,
                                         const Account& account):
      UpgradeAction(std::chrono::system_clock::now(),
                    UpgradeAction::Type::Ship,
                    account.getUniverseSpeed(),
                    planet.getBuildingLevel(Building::Type::Shipyard),
                    planet.getBuildingLevel(Building::Type::ResearchLab),
                    planet.getBuildingLevel(Building::Type::RoboticsFactory),
                    planet.getBuildingLevel(Building::Type::NaniteFactory)),
      m_ship(ship)
    {
      // Nothing to do here.
    }

    ShipUpgradeAction::~ShipUpgradeAction() {}

  }
}
