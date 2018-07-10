
#include "Account.h"

namespace ogame {
  namespace core {

    Account::Account(const unsigned& uuid, const std::string& name):
      m_uuid(uuid),
      m_name(name)
    {
      // Nothing to do.
    }

    Account::~Account() {}

  }
}
