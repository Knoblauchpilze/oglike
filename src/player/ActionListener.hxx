#ifndef ACTIONLISTENER_HXX
#define ACTIONLISTENER_HXX

#include "ActionListener.h"
#include "DataModelException.h"

namespace ogame {
  namespace player {

    inline
    const ActionListener::Action& ActionListener::getAction() const noexcept {
      return m_action;
    }

    inline
    const bool ActionListener::hasAction() const noexcept {
      return m_action != Action::None;
    }

    inline
    void ActionListener::setAction(const ActionListener::Action& action) {
      m_action = action;
    }
  }
}

#endif // ACTIONLISTENER_HXX
