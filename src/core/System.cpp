
#include "System.h"
#include "SystemException.h"
#include "Galaxy.h"

namespace ogame {
  namespace core {

    System::System(const unsigned& index, const unsigned& planetsCount, Galaxy* galaxy):
      m_index(index),
      m_parent(galaxy),
      m_planets(),
      m_coordinates(m_parent == nullptr ? 0u : m_parent->getIndex(), index)
    {
      create(planetsCount);
    }

    System::~System()
    {
      //dtor
    }

    bool System::operator==(const System& other) const noexcept {
      return other.m_index == m_index && (
        (m_parent == nullptr && other.m_parent == nullptr) ||
        (m_parent != nullptr && other.m_parent != nullptr && *m_parent == *other.m_parent)
      );
    }

    const Planet& System::operator[](const unsigned& index) const {
      if (index >= m_planets.size()) {
        throw SystemException("Cannot access out of bounds planet " + std::to_string(index) + " in system " + std::to_string(m_index));
      }
      else if (m_planets[index] == nullptr) {
        throw SystemException("Cannot retrieve invalid planet " + std::to_string(index) + " in system " + std::to_string(m_index));
      }
      return *m_planets[index];
    }

    Planet& System::operator[](const unsigned& index) {
      if (index >= m_planets.size()) {
        throw SystemException("Cannot access out of bounds planet " + std::to_string(index) + " in system " + std::to_string(m_index));
      }
      else if (m_planets[index] == nullptr) {
        throw SystemException("Cannot retrieve invalid planet " + std::to_string(index) + " in system " + std::to_string(m_index));
      }
      return *m_planets[index];
    }

    const unsigned& System::getGalaxyIndex() const {
      if (m_parent == nullptr) {
        throw SystemException(std::string("Could not retrieve galaxy of system ") + std::to_string(getIndex()) + " no associated galaxy");
      }
      return m_parent->getIndex();
    }

    const int System::getPositionOf(const Planet& planet) const {
      int index = 0;
      while (index < m_planets.size()) {
        if (m_planets[index] != nullptr && *m_planets[index] == planet) {
          return index;
        }
        ++index;
      }
      throw SystemException(std::string("Could not find index of planet ") + planet.getName() + " in system " + std::to_string(m_index));
    }

    const bool System::findPosition(unsigned& position,
                                    const unsigned& minStartingPosition,
                                    const unsigned& maxStartingPosition) const
    {
      // We assume that we can only give a position between minStartingPosition and maxStartingPosition.
      bool found = false;
      unsigned currentPosition = minStartingPosition;
      while (!found && currentPosition < m_planets.size() && currentPosition <= maxStartingPosition) {
        if (m_planets[currentPosition] != nullptr) {
          if (!m_planets[currentPosition]->isColonized()) {
            position = currentPosition;
            found = true;
          }
        }
        ++currentPosition;
      }
      return found;
    }

    void System::create(const unsigned& planetsCount) {
      m_planets.resize(planetsCount);
      for (unsigned indexPlanet = 0 ; indexPlanet < planetsCount ; ++indexPlanet) {
        m_planets[indexPlanet] = std::make_shared<Planet>(indexPlanet, std::string(""), this);
      }
    }

  }
}
