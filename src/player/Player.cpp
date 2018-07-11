
#include "Player.h"

namespace ogame {
  namespace player {

    Player::Player(const std::string& name,
                   core::CommunityShPtr community):
      m_uuid(0u),
      m_community(community)
    {
      // Try to create the player in this community.
      if (m_community == nullptr) {
        throw PlayerException(std::string("Cannot create player " ) + name + " with invalid community");
      }
      m_uuid = m_community->createPlayer(name);
    }

    Player::~Player() {}

  }
}
