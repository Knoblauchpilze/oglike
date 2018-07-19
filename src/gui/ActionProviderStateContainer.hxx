#ifndef ACTIONPROVIDERSTATECONTAINER_HXX
#define ACTIONPROVIDERSTATECONTAINER_HXX

#include "ActionProviderStateContainer.h"
#include "DataModelException.h"

namespace ogame {
  namespace gui {

    inline
    void ActionProviderStateContainer::onActionTriggered(const player::GeneralDataModel& model) {}

    inline
    void ActionProviderStateContainer::onStateModified() {
      // Trigger this action if needed.
      if (getStatePrivate() == StateContainer::State::Selected) {
        try {
          setActiveView(m_view);
        }
        catch (const player::DataModelException& e) {
          std::cerr << "[STATE] Could not assign view " << static_cast<int>(m_view) << " to data model:" << std::endl << e.what() << std::endl;
        }
      }
    }

  }
}


#endif // ACTIONPROVIDERSTATECONTAINER_HXX
