
#include "StateContainer.h"

namespace ogame {
  namespace gui {

    StateContainer::StateContainer(const std::string& name,
                                   const State& initState,
                                   const StateAssociation& colors,
                                   const FailPolicy& policy):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::Mouse),
      m_state(initState),
      m_policy(policy),
      m_colors(colors)
    {
      // Assign the background color based on the initial state.
      assignColorFromState(m_state);
    }

    StateContainer::~StateContainer() {}

  }
}

