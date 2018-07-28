
#include "Account.h"

namespace ogame {
  namespace core {

    Account::Account(const unsigned& playerUuid,
                     UniverseShPtr universe,
                     CommunityShPtr community):
      m_community(community),
      m_playerUuid(playerUuid),
      m_universe(universe),
      m_antimatter(0.0f),

      m_availablePlanetsSlots(1u),
      m_occupiedPlanetsSlots(0u),
      m_planets(),
      m_researches(),
      m_researchUpgrades()
    {
      initializeResearch();
    }

    Account::~Account() {}

    bool Account::operator==(const Account& other) const noexcept {
      return m_playerUuid == other.m_playerUuid && m_universe->getUuid() == other.m_universe->getUuid();
    }

    const std::string& Account::getUniverseName() const noexcept {
      if (m_community == nullptr) {
        throw AccountException(std::string("Could not get null community for player account " + std::to_string(m_playerUuid)));
      }
      return m_community->getUniverseName(m_universe->getUuid());
    }

    const System& Account::getSystem(const SystemCoordinates& coordinates) const {
      if (m_universe == nullptr) {
        throw AccountException(std::string("Could not retrieve system for coordinates for player ") + getPlayerName() + " invalid null universe");
      }

      return (*m_universe)[coordinates.getGalaxy()][coordinates.getSystem()];
    }

    const unsigned& Account::getUniverseSpeed() const {
      if (m_universe == nullptr) {
        throw AccountException(std::string("Could not retrieve universe speed for player ") + getPlayerName() + " invalid null universe");
      }
      return m_universe->getSpeed();
    }

    void Account::createUpgradeAction(const Research::Type& type) {
      // 
      ResearchShPtr research = nullptr;
      unsigned indexTech = 0u;
      while (indexTech < m_researches.size() && research == nullptr) {
        if (m_researches[indexTech] != nullptr && m_researches[indexTech]->getType() == type) {
          research = m_researches[indexTech];
        }
        ++indexTech;
      }

      if (indexTech >= m_researches.size() || research == nullptr) {
        const std::string errorMessage = std::string("Cannot create upgrade for research ") +
          std::to_string(static_cast<int>(type)) +
          ", data not available in account " +
          getPlayerName();
        throw PlanetException(errorMessage);
      }

      
    }

  }
}
