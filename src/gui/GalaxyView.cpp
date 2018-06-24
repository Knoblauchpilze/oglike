
#include "GalaxyView.h"

namespace ogame {
  namespace gui {

    GalaxyView::GalaxyView(const unsigned& width, const unsigned& height):
      view::GraphicContainer(std::string("Galaxy view"),
                             view::utils::Area(),
                             view::EventListener::Interaction::MouseButton)
    {
      // Nothing to do.
    }

    GalaxyView::~GalaxyView() {}

  }
}
