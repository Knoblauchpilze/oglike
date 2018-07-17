#ifndef ACTIONPROVIDERSTATECONTAINER_HXX
#define ACTIONPROVIDERSTATECONTAINER_HXX

#include "ActionProviderStateContainer.h"

#include <iostream>

namespace ogame {
  namespace gui {

    inline
    void ActionProviderStateContainer::onActionTriggered(const player::DataModel& model) {}

    inline
    void ActionProviderStateContainer::onStateModified() {
      // Trigger this action if needed.
      if (getStatePrivate() == StateContainer::State::Selected) {
        setActiveView(m_view);
      }
    }

  }
}


#endif // ACTIONPROVIDERSTATECONTAINER_HXX
