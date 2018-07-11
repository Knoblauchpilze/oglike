#ifndef UNIVERSE_HXX
#define UNIVERSE_HXX

#include "Universe.h"

namespace ogame {
  namespace core {

    inline
    bool Universe::operator==(const Universe& other) const {
      return m_index == other.m_index;
    }

    inline
    bool Universe::operator<(const Universe& other) const {
      return m_index < other.m_index;
    }

    inline
    const unsigned& Universe::getUuid() const noexcept {
      return m_index;
    }

    inline
    const bool Universe::checkForDuplicatedAccounts(const Account& account) const {
      for (unsigned indexAccount = 0u ; indexAccount < m_accounts.size() ; ++indexAccount) {
        if (*m_accounts[indexAccount] == account) {
          return true;
        }
      }
      return false;
    }

  }
}

#endif // UNIVERSE_HXX
