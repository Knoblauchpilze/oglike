
#include "Account.h"

namespace ogame {
  namespace core {

    Account::Account(const unsigned& playerUuid,
                     const unsigned& universeUuid,
                     CommunityShPtr community):
      m_community(community),
      m_playerUuid(playerUuid),
      m_universeUuid(universeUuid)
    {
      // Nothing to do.
    }

    Account::~Account() {}

  }
}
