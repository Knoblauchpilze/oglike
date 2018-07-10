#ifndef ACCOUNT_HXX
#define ACCOUNT_HXX

#include "Account.h"

namespace ogame {
  namespace core {

    inline
    bool Account::operator==(const Account& other) const noexcept {
      return m_uuid == other.m_uuid;
    }

    inline
    const unsigned& Account::getUuid() const noexcept {
      return m_uuid;
    }

    inline
    const std::string& Account::getName() const noexcept {
      return m_name;
    }

    inline
    const std::string& Account::getCommunity() const noexcept {
      return m_community;
    }

    inline
    const std::string& Account::getUniverse() const noexcept {
      return m_universe;
    }

    inline
    void Account::setCommunity(const std::string& community) {
      m_community = community;
    }

    inline
    void Account::setUniverse(const std::string& universe) {
      m_universe = universe;
    }

  }
}

#endif // ACCOUNT_HXX
