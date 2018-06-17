
#include "Galaxy.h"
#include "GalaxyException.h"

namespace ogame {
  namespace core {

    Galaxy::Galaxy(const unsigned& index, const unsigned& systemsCount):
      m_index(index),
      m_systems()
    {
      create(systemsCount);
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

    void Galaxy::create(const unsigned& systemsCount) {
      m_systems.resize(systemsCount);
      for (unsigned indexSystem = 0 ; indexSystem < systemsCount ; ++indexSystem) {
        m_systems[indexSystem] = nullptr;
      }
    }

  }
}
