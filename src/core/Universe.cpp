
#include "Universe.h"
#include "UniverseException.h"

namespace ogame {
  namespace core {

    Universe::Universe(const unsigned& index, const unsigned& galaxiesCount):
      m_index(index),
      m_galaxies()
    {
      create(galaxiesCount);
    }

    Universe::~Universe()
    {
      //dtor
    }

    bool Universe::operator==(const Universe& other) const {
      return m_index == other.m_index;
    }

    bool Universe::operator<(const Universe& other) const {
      return m_index < other.m_index;
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

    void Universe::create(const unsigned& galaxiesCount) {
      m_galaxies.clear();
      m_galaxies.resize(galaxiesCount);
      for (unsigned indexGalaxy = 0 ; indexGalaxy < galaxiesCount ; ++indexGalaxy) {
        m_galaxies[indexGalaxy] = nullptr;
      }
    }

  }
}
