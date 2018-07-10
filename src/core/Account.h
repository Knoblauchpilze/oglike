#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <memory>

namespace ogame {
  namespace core {

    class Account
    {
      public:

        Account(const unsigned& uuid, const std::string& name = std::string());

        ~Account();

        bool operator==(const Account& other) const noexcept;

        const unsigned& getUuid() const noexcept;

        const std::string& getName() const noexcept;

        const std::string& getCommunity() const noexcept;

        const std::string& getUniverse() const noexcept;

        void setCommunity(const std::string& community);

        void setUniverse(const std::string& universe);

      private:

        unsigned m_uuid;
        std::string m_name;
        std::string m_community;
        std::string m_universe;

    };

    using AccountShPtr = std::shared_ptr<Account>;
  }
}

#include "Account.hxx"

#endif // ACCOUNT_H
