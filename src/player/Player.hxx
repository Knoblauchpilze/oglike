#ifndef PLAYER_HXX
#define PLAYER_HXX

#include "Player.h"

namespace ogame {
  namespace player {

    inline
    core::AccountShPtr Player::getAccount() const noexcept {
      return m_account;
    }

    inline
    const std::string& Player::getName() const noexcept {
      return m_name;
    }

    inline
    void Player::setAccount(core::AccountShPtr account) {
      m_account = account;
    }

  }
}

#endif // PLAYER_HXX
