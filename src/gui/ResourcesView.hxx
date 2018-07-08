#ifndef RESOURCESVIEW_HXX
#define RESOURCESVIEW_HXX

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "LabelledPicture.h"
#include "FontFactory.h"
#include "ComponentFactory.h"

namespace ogame {
  namespace gui {

    inline
    LabelledPictureShPtr ResourcesView::createResourcePanel(const std::string& name,
                                                            const float& value,
                                                            const std::string& resource) const
    {
      return ComponentFactory::createLabelledPicturePanel(
        name,
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/times.ttf"),
          255, 255, 255
        ),
        std::string("data/img/") + resource + ".bmp",
        std::to_string(static_cast<int>(value)),
        LabelledPicture::Alignment::Above
      );
    }

  }
}

#endif // RESOURCESVIEW_HXX
