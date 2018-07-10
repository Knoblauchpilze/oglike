
#include "Player.h"

namespace ogame {
  namespace player {

    Player::Player(const std::string& name):
      m_account(nullptr),
      m_name(name)
    {
      // Nothing to do.
    }

    Player::~Player() {}

  }
}
