#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <string>
#include <vector>
#include <memory>

#include "Galaxy.h"
#include "Account.h"

namespace ogame {
  namespace core {

    class Galaxy;

    class Universe
    {
      public:

        Universe(const unsigned& index,
                 const unsigned& galaxiesCount,
                 const unsigned& systemsCount,
                 const unsigned& planetsCount,
                 const unsigned& minStartingPosition = 5u,
                 const unsigned& maxStartingPosition = 9u);

        virtual ~Universe();

        bool operator==(const Universe& other) const;

        bool operator<(const Universe& other) const;

        const unsigned& getUuid() const noexcept;

        const Galaxy& operator[](const unsigned& index) const;

        void createAccount(AccountShPtr account);

      private:

        void create(const unsigned& galaxiesCount,
                    const unsigned& systemsCount,
                    const unsigned& planetsCount);

        const bool checkForDuplicatedAccounts(const Account& account) const;

        const bool findPositionForAccount(unsigned& galaxy, unsigned& system, unsigned& position) const;

      private:

        const unsigned m_index;
        std::vector<GalaxyShPtr> m_galaxies;
        unsigned m_minStartPos;
        unsigned m_maxStartPos;
        std::vector<AccountShPtr> m_accounts;

    };

    using UniverseShPtr = std::shared_ptr<Universe>;
  }
}

#include "Universe.hxx"

#endif // UNIVERSE_H
