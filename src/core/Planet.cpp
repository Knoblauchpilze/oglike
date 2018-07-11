
#include "Planet.h"
#include "System.h"
#include "PlanetException.h"

#include <iostream>

namespace ogame {
  namespace core {

    Planet::Planet(const unsigned& index, const std::string& name, System* system):
      m_index(index),
      m_name(name),
      m_parent(system),
      m_account(nullptr)
    {
      create();
    }

    Planet::~Planet()
    {
      //dtor
    }

    const unsigned Planet::getPositionInSystem() const {
      return m_parent->getPositionOf(*this);
    }

    const unsigned& Planet::getSystemIndex() const {
      if (m_parent == nullptr) {
        throw PlanetException(std::string("Could not retrieve system of planet ") + std::to_string(m_index) + " no associated system");
      }
      return m_parent->getIndex();
    }

    const unsigned& Planet::getGalaxyIndex() const {
      if (m_parent == nullptr) {
        throw PlanetException(std::string("Could not retrieve galaxy of planet ") + std::to_string(m_index) + " no associated system");
      }
      return m_parent->getGalaxyIndex();
    }

    void Planet::assignToAccount(AccountShPtr account) {
      // Check account's validity.
      if (account == nullptr) {
        const std::string errorMessage = std::string("Cannot assign invalid account to planet [") +
          std::to_string(getGalaxyIndex()) + ":" +
          std::to_string(getSystemIndex()) + ":" +
          std::to_string(m_index) + "]";
        throw PlanetException(errorMessage);
      }

      // Assign the account to this planet.
      m_account = account;

      // Assign a default name
      m_name = generateRandomName(15u);

      std::cout << "[PLANET] Assigned new planet "
                << m_name
                << " at [" << getGalaxyIndex() << ":" << getSystemIndex() << ":" << m_index << "]"
                << " to player " << account->getPlayerName()
                << std::endl;
    }

    void Planet::create() {
      m_resources.push_back(std::make_shared<ResourceDeposit>(std::string("Metal"), 500.0f, 10000.0f));
      m_resources.push_back(std::make_shared<ResourceDeposit>(std::string("Cristal"), 500.0f, 10000.0f));
      m_resources.push_back(std::make_shared<ResourceDeposit>(std::string("Deuterium"), 0.0f, 10000.0f));
    }

  }
}
