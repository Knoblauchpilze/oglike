
#include "Galaxy.h"
#include "GalaxyException.h"

namespace ogame {
  namespace core {

    Galaxy::Galaxy(const unsigned& index,
                   const unsigned& systemsCount,
                   const unsigned& planetsCount,
                   const bool instantiate):
      m_index(index),
      m_systems()
    {
      if (instantiate) {
        create(systemsCount, planetsCount);
      }
    }

    Galaxy::~Galaxy()
    {
      //dtor
    }

    const System& Galaxy::operator[](const unsigned& index) const {
      if (index >= m_systems.size()) {
        throw GalaxyException("Cannot access out of bounds system " + std::to_string(index) + " in galaxy " + std::to_string(m_index));
      }
      else if (m_systems[index] == nullptr) {
        throw GalaxyException("Cannot retrieve invalid system " + std::to_string(index) + " in galaxy " + std::to_string(m_index));
      }
      return *m_systems[index];
    }

    void Galaxy::create(const unsigned& systemsCount,
                        const unsigned& planetsCount)
    {
      m_systems.resize(systemsCount);
      for (unsigned indexSystem = 0 ; indexSystem < systemsCount ; ++indexSystem) {
        m_systems[indexSystem] = std::make_shared<System>(indexSystem, planetsCount, this);
      }
    }

  }
}
