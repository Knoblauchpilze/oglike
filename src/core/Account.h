#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <memory>
#include "Community.h"
#include "Planet.h"
#include "Universe.h"
#include "SystemCoordinates.h"
#include "Research.h"
#include "ResearchUpgradeAction.h"

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

        const std::string& getPlayerName() const;

        const std::string& getCommunityName() const;

        const std::string& getUniverseName() const;

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

        const core::Research& getResearchData(const Research::Type& type) const;

        const unsigned& getUniverseSpeed() const;

        void createUpgradeAction(const Research::Type& type, const Planet& planet);

        const std::vector<std::shared_ptr<ResearchUpgradeAction>>& getResearchUpgrades() const noexcept;

        const bool canResearch(const Research& research) const;

        void upgrade(const Research::Type& research);

      private:

        void initializeResearch();

        const unsigned getIndexForResearch(const Research::Type& type) const noexcept;

        ResearchShPtr getResearchOrThrow(const Research::Type& type) const;

        core::Research& getResearchDataPrivate(const Research::Type& type);

      private:

        CommunityShPtr m_community;
        unsigned m_playerUuid;
        std::shared_ptr<Universe> m_universe;
        float m_antimatter;

        unsigned m_availablePlanetsSlots;
        unsigned m_occupiedPlanetsSlots;
        std::vector<Planet*> m_planets;
        std::vector<ResearchShPtr> m_researches;

        std::vector<std::shared_ptr<ResearchUpgradeAction>> m_researchUpgrades;

    };

    using AccountShPtr = std::shared_ptr<Account>;
  }
}

#include "Account.hxx"

#endif // ACCOUNT_H
