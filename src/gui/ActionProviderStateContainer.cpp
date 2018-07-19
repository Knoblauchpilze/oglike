
#include "ActionProviderStateContainer.h"

namespace ogame {
  namespace gui {

    ActionProviderStateContainer::ActionProviderStateContainer(const std::string& name,
                                                               const State& initState,
                                                               const StateAssociation& colors,
                                                               const player::View& view,
                                                               player::AbstractDataModel* model,
                                                               const FailPolicy& policy):
      StateContainer(name, initState, colors, policy),
      player::GeneralActionListener(model),
      m_view(view)
    {
      // Nothing to do here.
    }

    ActionProviderStateContainer::~ActionProviderStateContainer() {}

  }
}
