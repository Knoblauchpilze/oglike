
#include "ElementDescriptionPanel.h"

namespace ogame {
  namespace gui {

    ElementDescriptionPanel::ElementDescriptionPanel(const std::string& name):
      view::GraphicContainer(name,
                             view::utils::Area())
    {
      // Nothing to do here.
    }

    ElementDescriptionPanel::~ElementDescriptionPanel() {}

  }
}
