#ifndef ACCOUNT_HXX
#define ACCOUNT_HXX

#include "Account.h"
#include "AccountException.h"
#include "ResearchFactory.h"

namespace ogame {
  namespace core {

    inline
    const unsigned& Account::getPlayerUuid() const noexcept {
      return m_playerUuid;
    }

    inline
    const std::string& Account::getPlayerName() const noexcept {
      if (m_community == nullptr) {
        throw AccountException(std::string("Could not get null community for player account ") + std::to_string(m_playerUuid));
      }
      return m_community->getPlayerName(m_playerUuid);
    }

    inline
    const std::string& Account::getCommunityName() const noexcept {
      if (m_community == nullptr) {
        throw AccountException(std::string("Could not get null community for player account " + std::to_string(m_playerUuid)));
      }
      return m_community->getName();
    }

    inline
    CommunityShPtr Account::getCommunity() const noexcept {
      return m_community;
    }

    inline
    const float Account::getAntimatterQuantity() const noexcept {
      return m_antimatter;
    }

    inline
    const unsigned& Account::getAvailablePlanetsSlots() const noexcept {
      return m_availablePlanetsSlots;
    }

    inline
    const unsigned& Account::getOccupiedPlanetsSlots() const noexcept {
      return m_occupiedPlanetsSlots;
    }

    inline
    void Account::incrementAvailablePlanetsSlots() noexcept {
      ++m_availablePlanetsSlots;
    }

    inline
    const Planet& Account::getHomeWorld() const {
      if (m_planets.size() == 0 || m_planets[0] == nullptr) {
        throw AccountException(std::string("Could not retrieve home planet for player ") + getPlayerName() + ", no planet filled");
      }
      return *m_planets[0];
    }

    inline
    Planet& Account::getHomeWorld() {
      if (m_planets.size() == 0 || m_planets[0] == nullptr) {
        throw AccountException(std::string("Could not retrieve home planet for player ") + getPlayerName() + ", no planet filled");
      }
      return *m_planets[0];
    }

    inline
    void Account::setHomePlanet(Planet* planet) {
      if (planet == nullptr) {
        throw AccountException(std::string("Could not set null home planet for player " + getPlayerName()));
      }
      m_planets.insert(m_planets.begin(), planet);
      m_occupiedPlanetsSlots = m_planets.size();
      m_availablePlanetsSlots = m_planets.size();
    }

    inline
    const std::vector<Planet*>& Account::getPlanets() const noexcept {
      return m_planets;
    }

    inline
    const unsigned Account::getLevelForTechnology(const Research::Type& type) const {
      // Traverse the set of researches.
      unsigned indexTech = 0u;
      while (indexTech < m_researches.size()) {
        if (m_researches[indexTech] != nullptr && m_researches[indexTech]->getType() == type) {
          return m_researches[indexTech]->getLevel();
        }
        ++indexTech;
      }

      // Research not found, assume 0 level.
      return 0u;
    }

    inline
    const core::Research& Account::getResearchData(const Research::Type& type) const {
      // Traverse the set of researches.
      unsigned indexTech = 0u;
      while (indexTech < m_researches.size()) {
        if (m_researches[indexTech] != nullptr && m_researches[indexTech]->getType() == type) {
          return *m_researches[indexTech];
        }
        ++indexTech;
      }

      // Research not found, this is a problem.
      const std::string errorMessage = std::string("Cannot retrieve data for research ") +
        std::to_string(static_cast<int>(type)) +
        ", data not available in account " +
        getPlayerName();
      throw AccountException(errorMessage);
    }

    inline
    void Account::initializeResearch() {
      // Create all research in this account.
      m_researches.push_back(core::ResearchFactory::createEnergyResearch());
      m_researches.push_back(core::ResearchFactory::createLaserResearch());
      m_researches.push_back(core::ResearchFactory::createIonsResearch());
      m_researches.push_back(core::ResearchFactory::createHyperspaceResearch());
      m_researches.push_back(core::ResearchFactory::createPlasmaResearch());
      m_researches.push_back(core::ResearchFactory::createCombustionDriveResearch());
      m_researches.push_back(core::ResearchFactory::createImpulseDriveResearch());
      m_researches.push_back(core::ResearchFactory::createHyperspaceDriveResearch());
      m_researches.push_back(core::ResearchFactory::createEspionageResearch());
      m_researches.push_back(core::ResearchFactory::createComputerResearch());
      m_researches.push_back(core::ResearchFactory::createAstrophysicsResearch());
      m_researches.push_back(core::ResearchFactory::createIRNResearch());
      m_researches.push_back(core::ResearchFactory::createGravitonResearch());
      m_researches.push_back(core::ResearchFactory::createWeaponResearch());
      m_researches.push_back(core::ResearchFactory::createShieldingResearch());
      m_researches.push_back(core::ResearchFactory::createArmourResearch());
    }

  }
}

#endif // ACCOUNT_HXX
