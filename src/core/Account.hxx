#ifndef ACCOUNT_HXX
#define ACCOUNT_HXX

#include "Account.h"
#include "AccountException.h"

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

  }
}

#endif // ACCOUNT_HXX
