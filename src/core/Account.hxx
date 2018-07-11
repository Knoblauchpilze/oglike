#ifndef ACCOUNT_HXX
#define ACCOUNT_HXX

#include "Account.h"
#include "AccountException.h"

namespace ogame {
  namespace core {

    inline
    bool Account::operator==(const Account& other) const noexcept {
      return m_playerUuid == other.m_playerUuid && m_universeUuid == other.m_universeUuid;
    }

    inline
    const unsigned& Account::getPlayerUuid() const noexcept {
      return m_playerUuid;
    }

    inline
    const std::string& Account::getPlayerName() const noexcept {
      if (m_community == nullptr) {
        throw AccountException(std::string("Could not get null community for player account ") + std::to_string(m_playerUuid));
      }
      return m_community->getPlayerName(m_playerUuid);
    }

    inline
    const std::string& Account::getCommunityName() const noexcept {
      if (m_community == nullptr) {
        throw AccountException(std::string("Could not get null community for player account " + std::to_string(m_playerUuid)));
      }
      return m_community->getName();
    }

    inline
    const std::string& Account::getUniverseName() const noexcept {
      if (m_community == nullptr) {
        throw AccountException(std::string("Could not get null community for player account " + std::to_string(m_playerUuid)));
      }
      return m_community->getUniverseName(m_universeUuid);
    }

    inline
    CommunityShPtr Account::getCommunity() const noexcept {
      return m_community;
    }

  }
}

#endif // ACCOUNT_HXX
