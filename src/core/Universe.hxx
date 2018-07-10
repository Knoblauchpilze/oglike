#ifndef UNIVERSE_HXX
#define UNIVERSE_HXX

#include "Universe.h"

namespace ogame {
  namespace core {

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
