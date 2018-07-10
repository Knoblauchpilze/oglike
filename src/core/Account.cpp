
#include "Account.h"

namespace ogame {
  namespace core {

    Account::Account(const unsigned& uuid, const std::string& name):
      m_uuid(uuid),
      m_name(name),
      m_community("Default community"),
      m_universe("Default universe")
    {
      // Nothing to do.
    }

    Account::~Account() {}

  }
}
