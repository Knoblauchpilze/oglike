
#include "Planet.h"
#include "System.h"
#include "PlanetException.h"

namespace ogame {
  namespace core {

    Planet::Planet(const unsigned& index, const std::string& name, System* system):
      m_index(index),
      m_name(name),
      m_parent(system)
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

    void Planet::create() {
      m_resources.push_back(std::make_shared<ResourceDeposit>(std::string("Metal"), 500.0f, 10000.0f));
      m_resources.push_back(std::make_shared<ResourceDeposit>(std::string("Cristal"), 500.0f, 10000.0f));
      m_resources.push_back(std::make_shared<ResourceDeposit>(std::string("Deuterium"), 0.0f, 10000.0f));
    }

  }
}
