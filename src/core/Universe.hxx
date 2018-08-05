#ifndef UNIVERSE_HXX
#define UNIVERSE_HXX

#include "Universe.h"

namespace ogame {
  namespace core {

    inline
    bool Universe::operator==(const Universe& other) const {
      return m_index == other.m_index;
    }

    inline
    bool Universe::operator<(const Universe& other) const {
      return m_index < other.m_index;
    }

    inline
    const unsigned& Universe::getUuid() const noexcept {
      return m_index;
    }

    inline
    const unsigned& Universe::getSpeed() const noexcept {
      return m_speed;
    }

    inline
    const unsigned Universe::getGalaxiesCount() const noexcept {
      return m_galaxies.size();
    }

    inline
    const std::vector<std::shared_ptr<Account>>& Universe::getAccounts() const noexcept {
      return m_accounts;
    }

  }
}

#endif // UNIVERSE_HXX
