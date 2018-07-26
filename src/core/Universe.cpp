
#include "Universe.h"
#include "UniverseException.h"

namespace ogame {
  namespace core {

    Universe::Universe(const unsigned& index,
                       const unsigned& galaxiesCount,
                       const unsigned& systemsCount,
                       const unsigned& planetsCount,
                       const unsigned& minStartingPosition,
                       const unsigned& maxStartingPosition,
                       const unsigned& speed):
      m_index(index),
      m_speed(speed),
      m_galaxies(),
      m_minStartPos(minStartingPosition),
      m_maxStartPos(maxStartingPosition),
      m_accounts()
    {
      create(galaxiesCount, systemsCount, planetsCount);
    }

    Universe::~Universe()
    {
      //dtor
    }

    const Galaxy& Universe::operator[](const unsigned& index) const {
      if (index >= m_galaxies.size()) {
        throw UniverseException("Cannot access out of bounds galaxy " + std::to_string(index) + " in universe " + std::to_string(m_index));
      }
      else if (m_galaxies[index] == nullptr) {
        throw UniverseException("Cannot retrieve invalid galaxy " + std::to_string(index) + " in universe " + std::to_string(m_index));
      }
      return *m_galaxies[index];
    }

    void Universe::createAccount(AccountShPtr account) {
      // Check whether this account is valid.
      if (account == nullptr) {
        throw UniverseException(std::string("Cannot create account for null player in universe ") + std::to_string(m_index));
      }

      // Check whether this account already exists.
      if (checkForDuplicatedAccounts(*account)) {
        const std::string errorMessage = std::string("Cannot create account for ") +
          account->getPlayerName() +
          " already existing in universe " + std::to_string(m_index);
        throw UniverseException(errorMessage);
      }

      // Select a position for this account.
      unsigned galaxy;
      unsigned system;
      unsigned position;
      const bool valid = findPositionForAccount(galaxy, system, position);
      if (!valid) {
        throw UniverseException(std::string("Could not find a valid position for account ") + account->getPlayerName() + " in universe " + std::to_string(m_index));
      }

      // Retrieve the planet described by the coordinates.
      Planet& planet = (*m_galaxies[galaxy])[system][position];

      // Assign the new player.
      planet.assignToAccount(account);

      // Add this account to this universe.
      m_accounts.push_back(account);
    }

    void Universe::create(const unsigned& galaxiesCount,
                          const unsigned& systemsCount,
                          const unsigned& planetsCount)
    {
      m_galaxies.clear();
      m_galaxies.resize(galaxiesCount);
      for (unsigned indexGalaxy = 0 ; indexGalaxy < galaxiesCount ; ++indexGalaxy) {
        m_galaxies[indexGalaxy] = std::make_shared<Galaxy>(indexGalaxy, systemsCount, planetsCount);
      }
    }

    const bool Universe::checkForDuplicatedAccounts(const Account& account) const {
      for (unsigned indexAccount = 0u ; indexAccount < m_accounts.size() ; ++indexAccount) {
        if (*m_accounts[indexAccount] == account) {
          return true;
        }
      }
      return false;
    }

    const bool Universe::findPositionForAccount(unsigned& galaxy, unsigned& system, unsigned& position) const {
      // We assume that we can only give a position between m_minStartPos and m_maxStartPos.
      bool found = false;
      unsigned currentGalaxy = 0u;
      unsigned currentSystem = 0u;
      while (!found && currentGalaxy < m_galaxies.size()) {
        if (m_galaxies[currentGalaxy] != nullptr) {
          found = m_galaxies[currentGalaxy]->findPosition(system, position, m_minStartPos, m_maxStartPos);
          if (found) {
            galaxy = currentGalaxy;
          }
        }
        ++currentGalaxy;
      }
      return found;
    }

  }
}
