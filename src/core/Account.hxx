#ifndef ACCOUNT_HXX
#define ACCOUNT_HXX

#include "Account.h"
#include "AccountException.h"

namespace ogame {
  namespace core {

    inline
    bool Account::operator==(const Account& other) const noexcept {
      return m_playerUuid == other.m_playerUuid && m_universeUuid == other.m_universeUuid;
    }

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
    const std::string& Account::getUniverseName() const noexcept {
      if (m_community == nullptr) {
        throw AccountException(std::string("Could not get null community for player account " + std::to_string(m_playerUuid)));
      }
      return m_community->getUniverseName(m_universeUuid);
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
    const core::Planet& Account::getHomeWorld() const {
      if (m_planets.size() == 0 || m_planets[0] == nullptr) {
        throw AccountException(std::string("Could not retrieve home planet for player ") + getPlayerName() + ", no planet filled");
      }
      return *m_planets[0];
    }

    inline
    core::Planet& Account::getHomeWorld() {
      if (m_planets.size() == 0 || m_planets[0] == nullptr) {
        throw AccountException(std::string("Could not retrieve home planet for player ") + getPlayerName() + ", no planet filled");
      }
      return *m_planets[0];
    }

    inline
    void Account::setHomePlanet(core::Planet* planet) {
      if (planet == nullptr) {
        throw AccountException(std::string("Could not set null home planet for player " + getPlayerName()));
      }
      m_planets.insert(m_planets.begin(), planet);
      m_planets.push_back(planet);
      m_planets.push_back(planet);
      m_planets.push_back(planet);
      m_planets.push_back(planet);
      m_planets.push_back(planet);
      m_planets.push_back(planet);
      m_planets.push_back(planet);
      m_planets.push_back(planet);
      m_planets.push_back(planet);
      m_planets.push_back(planet);
      m_planets.push_back(planet);
      m_occupiedPlanetsSlots = m_planets.size();
      m_availablePlanetsSlots = m_planets.size();
    }

    inline
    const std::vector<core::Planet*>& Account::getPlanets() const noexcept {
      return m_planets;
    }

  }
}

#endif // ACCOUNT_HXX
