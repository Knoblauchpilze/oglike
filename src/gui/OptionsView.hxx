#ifndef OPTIONSVIEW_HXX
#define OPTIONSVIEW_HXX

#include "OptionsView.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    inline
    LabelContainerShPtr OptionsView::createOptionPanel(const std::string& name, const std::string& text) const {
      LabelContainerShPtr label = ComponentFactory::createLabelPanel(
        name,
        text,
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/times.ttf"),
          255, 255, 255, SDL_ALPHA_OPAQUE,
          15
        )
      );

      if (label != nullptr) {
        label->setBackgroundColor(SDL_Color{0, 0, 0, SDL_ALPHA_OPAQUE});
      }

      return label;
    }

  }
}

#endif // OPTIONSVIEW_HXX
