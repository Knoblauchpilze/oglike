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

  }
}

#endif // ACCOUNT_HXX
