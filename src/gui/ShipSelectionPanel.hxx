#ifndef SHIPSELECTIONPANEL_HXX
#define SHIPSELECTIONPANEL_HXX

#include "ShipSelectionPanel.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    inline
    void ShipSelectionPanel::setCount(const unsigned& count) {
      lock();

      BackgroundedLabel* label = getChild<BackgroundedLabel*>(std::string("image"));
      if (checkChild(label, std::string("Label panel"))) {
        label->setText(std::to_string(count));
      }

      makeDeepDirty();
      unlock();
    }

    inline
    BackgroundedLabelShPtr ShipSelectionPanel::createBackgroundedLabelContainer(const std::string& name,
                                                                                const std::string& picture)
    {
      return ComponentFactory::createBackgroundedLabelPanel(
        name,
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/upcfb.ttf"),
          219, 140, 40, SDL_ALPHA_OPAQUE
        ),
        picture,
        std::to_string(0),
        SDL_Color{14, 57, 83, SDL_ALPHA_OPAQUE},
        BackgroundedLabel::Alignment::BottomRight
      );
    }

  }
}

#endif // SHIPSELECTIONPANEL_HXX
