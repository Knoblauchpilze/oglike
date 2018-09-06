#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <string>
#include "Community.h"

namespace ogame {
  namespace player {

    class Player
    {
      public:

        Player(const std::string& name,
               core::CommunityShPtr community);

        ~Player();

        const unsigned& getUuid() const noexcept;

        const std::string& getName() const;

        core::CommunityShPtr getCommunity() const noexcept;

      private:

        unsigned m_uuid;
        core::CommunityShPtr m_community;

    };

    using PlayerShPtr = std::shared_ptr<Player>;
  }
}

#include "Player.hxx"

#endif // PLAYER_H
