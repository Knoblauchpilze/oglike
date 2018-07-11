
#include "ActionListener.h"

namespace ogame {
  namespace player {

    ActionListener::ActionListener(const Action& action):
      m_action(action)
    {
      // Nothing to do.
    }

    ActionListener::~ActionListener() {}

  }
}
