#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <string>
#include "Account.h"

namespace ogame {
  namespace player {

    class Player
    {
      public:

        Player(const std::string& name);

        ~Player();

        core::AccountShPtr getAccount() const noexcept;

        const std::string& getName() const noexcept;

        void setAccount(core::AccountShPtr account);

      private:

        core::AccountShPtr m_account;
        std::string m_name;

    };

    using PlayerShPtr = std::shared_ptr<Player>;
  }
}

#include "Player.hxx"

#endif // PLAYER_H
