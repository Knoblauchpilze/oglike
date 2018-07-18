
#include "ActionProviderStateContainer.h"

namespace ogame {
  namespace gui {

    ActionProviderStateContainer::ActionProviderStateContainer(const std::string& name,
                                                               const State& initState,
                                                               const StateAssociation& colors,
                                                               const player::View& view,
                                                               player::AbstractDataModel<player::Action>* model,
                                                               const FailPolicy& policy):
      StateContainer(name, initState, colors, policy),
      player::AbstractActionListener<player::Action>(model),
      m_view(view)
    {
      // Nothing to do here.
    }

    ActionProviderStateContainer::~ActionProviderStateContainer() {}

  }
}
