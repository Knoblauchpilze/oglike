#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <memory>
#include "Community.h"
#include "Planet.h"

namespace ogame {
  namespace core {

    class Planet;

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

        const float getAntimatterQuantity() const noexcept;

        const unsigned& getAvailablePlanetsSlots() const noexcept;
        
        const unsigned& getOccupiedPlanetsSlots() const noexcept;

        void incrementAvailablePlanetsSlots() noexcept;

        const core::Planet& getHomeWorld() const;

        core::Planet& getHomeWorld();

        void setHomePlanet(core::Planet* planet);

        const std::vector<core::Planet*>& getPlanets() const noexcept;

      private:

        CommunityShPtr m_community;
        unsigned m_playerUuid;
        unsigned m_universeUuid;
        float m_antimatter;
        
        unsigned m_availablePlanetsSlots;
        unsigned m_occupiedPlanetsSlots;
        std::vector<core::Planet*> m_planets;

    };

    using AccountShPtr = std::shared_ptr<Account>;
  }
}

#include "Account.hxx"

#endif // ACCOUNT_H
