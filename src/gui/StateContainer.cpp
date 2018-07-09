
#include "StateContainer.h"

namespace ogame {
  namespace gui {

    StateContainer::StateContainer(const std::string& name,
                                   const State& initState,
                                   const StateAssociation& colors):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::Mouse),
      m_state(initState),
      m_colors(colors)
    {
      // Nothing to do.
    }

    StateContainer::~StateContainer() {}

  }
}

