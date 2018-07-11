#ifndef COMMUNITY_HXX
#define COMMUNITY_HXX

#include "Community.h"
#include "CommunityException.h"

namespace ogame {
  namespace core {

    inline
    bool Community::operator==(const Community& other) const noexcept {
      return m_name == other.m_name;
    }

    inline
    const std::string& Community::getName() const noexcept {
      return m_name;
    }

    inline
    const std::string& Community::getPlayerName(const unsigned& playerUuid) const {
      if (m_players.size() <= playerUuid) {
        throw CommunityException(std::string("Cannot find name for player ") + std::to_string(playerUuid) + " in community " + getName());
      }
      return m_players[playerUuid];
    }

    inline
    const std::string& Community::getUniverseName(const unsigned& universeUuid) const {
      if (m_universes.size() <= universeUuid) {
        throw CommunityException(std::string("Cannot find name for universe ") + std::to_string(universeUuid) + " in community " + getName());
      }
      return m_universes[universeUuid];
    }

    inline
    bool Community::checkForDuplicatedUniverses(const std::string& name) const noexcept {
      std::vector<std::string>::const_iterator universe = m_universes.cbegin();
      while (universe != m_universes.cend()) {
        if (*universe == name) {
          return true;
        }
        ++universe;
      }
      return false;
    }

    inline
    bool Community::checkForDuplicatedPlayers(const std::string& name) const noexcept {
      std::vector<std::string>::const_iterator player = m_players.cbegin();
      while (player != m_players.cend()) {
        if (*player == name) {
          return true;
        }
        ++player;
      }
      return false;
    }

  }
}

#endif // COMMUNITY_HXX
