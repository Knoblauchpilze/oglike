#ifndef PLAYER_HXX
#define PLAYER_HXX

#include "Player.h"
#include "PlayerException.h"

namespace ogame {
  namespace player {

    inline
    const unsigned& Player::getUuid() const noexcept {
      return m_uuid;
    }

    inline
    const std::string& Player::getName() const noexcept {
      if (m_community == nullptr) {
        throw PlayerException(std::string("Could not get null community for player account " + std::to_string(m_uuid)));
      }
      return m_community->getPlayerName(m_uuid);
    }

    inline
    core::CommunityShPtr Player::getCommunity() const noexcept {
      return m_community;
    }

  }
}

#endif // PLAYER_HXX
