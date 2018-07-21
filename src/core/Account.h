#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <memory>
#include "Community.h"
#include "Planet.h"
#include "Universe.h"
#include "SystemCoordinates.h"
#include "Research.h"

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

        const Planet& getHomeWorld() const;

        Planet& getHomeWorld();

        void setHomePlanet(Planet* planet);

        const std::vector<Planet*>& getPlanets() const noexcept;

        const System& getSystem(const SystemCoordinates& coordinates) const;

        const unsigned getLevelForTechnology(const Research::Type& type) const;

      private:

        CommunityShPtr m_community;
        unsigned m_playerUuid;
        std::shared_ptr<Universe> m_universe;
        float m_antimatter;
        
        unsigned m_availablePlanetsSlots;
        unsigned m_occupiedPlanetsSlots;
        std::vector<Planet*> m_planets;
        std::vector<ResearchShPtr> m_researches;

    };

    using AccountShPtr = std::shared_ptr<Account>;
  }
}

#include "Account.hxx"

#endif // ACCOUNT_H
