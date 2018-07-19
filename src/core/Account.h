#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <memory>
#include "Community.h"
#include "Planet.h"
#include "Universe.h"
#include "SystemCoordinates.h"

namespace ogame {
  namespace core {

    class Planet;
    class System;
    class Universe;

    class Account
    {
      public:

        Account(const unsigned& playerUuid,
                std::shared_ptr<Universe> universe,
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

        const core::System& getSystem(const core::SystemCoordinates& coordinates) const;

      private:

        CommunityShPtr m_community;
        unsigned m_playerUuid;
        std::shared_ptr<Universe> m_universe;
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
