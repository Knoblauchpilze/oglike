
#include "System.h"
#include "SystemException.h"

namespace ogame {
  namespace core {

    System::System(const unsigned& index, const unsigned& planetsCount):
      m_index(index),
      m_planets()
    {
      create(planetsCount);
    }

    System::~System()
    {
      //dtor
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

    void System::create(const unsigned& planetsCount) {
      m_planets.resize(planetsCount);
      for (unsigned indexPlanet = 0 ; indexPlanet < planetsCount ; ++indexPlanet) {
        m_planets[indexPlanet] = nullptr;
      }
    }

  }
}
