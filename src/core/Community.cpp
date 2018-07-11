
#include "Community.h"
#include "CommunityException.h"

namespace ogame {
  namespace core {

    Community::Community(const std::string& name):
      m_name(name),
      m_universes()
    {
      // Nothing to do.
    }

    Community::~Community() {}

    const unsigned Community::createUniverse(const std::string& name) {
      // Check for duplicated universes.
      if (checkForDuplicatedUniverses(name)) {
        throw CommunityException(std::string("Cannot create duplicated universe ") + name + " in community " + getName());
      }

      // Add this universe.
      m_universes.push_back(name);

      // Return its identifier.
      return m_universes.size() - 1u;
    }

    const unsigned Community::createPlayer(const std::string& name) {
      // Check for duplicated players.
      if (checkForDuplicatedPlayers(name)) {
        throw CommunityException(std::string("Cannot create duplicated player ") + name + " in community " + getName());
      }

      // Add this player.
      m_players.push_back(name);

      // Return its identifier.
      return m_players.size() - 1u;
    }

  }
}
