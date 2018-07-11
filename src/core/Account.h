#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <memory>
#include "Community.h"

namespace ogame {
  namespace core {

    class Account
    {
      public:

        Account(const unsigned& playerUuid,
                const unsigned& universeUuid,
                CommunityShPtr community);

        ~Account();

        bool operator==(const Account& other) const noexcept;

        const unsigned& getPlayerUuid() const noexcept;

        const std::string& getPlayerName() const noexcept;

        const std::string& getCommunityName() const noexcept;

        const std::string& getUniverseName() const noexcept;

        CommunityShPtr getCommunity() const noexcept;

      private:

        CommunityShPtr m_community;
        unsigned m_playerUuid;
        unsigned m_universeUuid;

    };

    using AccountShPtr = std::shared_ptr<Account>;
  }
}

#include "Account.hxx"

#endif // ACCOUNT_H
