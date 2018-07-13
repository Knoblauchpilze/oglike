
#include "Account.h"

namespace ogame {
  namespace core {

    Account::Account(const unsigned& playerUuid,
                     const unsigned& universeUuid,
                     CommunityShPtr community):
      m_community(community),
      m_playerUuid(playerUuid),
      m_universeUuid(universeUuid),
      m_antimatter(0.0f),

      m_availablePlanetsSlots(1u),
      m_occupiedPlanetsSlots(0u),
      m_planets()
    {
      // Nothing to do.
    }

    Account::~Account() {}

  }
}
