#ifndef COMMUNITY_H
#define COMMUNITY_H

#include <memory>
#include <vector>
#include <string>

namespace ogame {
  namespace core {

    class Community
    {
      public:

        Community(const std::string& name);

        ~Community();

        bool operator==(const Community& other) const noexcept;

        const std::string& getName() const noexcept;

        const std::string& getPlayerName(const unsigned& playerUuid) const;

        const std::string& getUniverseName(const unsigned& universeUuid) const;

        const unsigned createUniverse(const std::string& name);

        const unsigned createPlayer(const std::string& name);

      private:

        bool checkForDuplicatedUniverses(const std::string& name) const noexcept;

        bool checkForDuplicatedPlayers(const std::string& name) const noexcept;

      private:

        std::string m_name;
        std::vector<std::string> m_universes;
        std::vector<std::string> m_players;

    };

    using CommunityShPtr = std::shared_ptr<Community>;
  }
}

#include "Community.hxx"

#endif // COMMUNITY_H
