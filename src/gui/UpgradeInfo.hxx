#ifndef UPGRADEINFO_HXX
#define UPGRADEINFO_HXX

#include "UpgradeInfo.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    inline
    LabelContainerShPtr UpgradeInfo::createLabelPanel(const std::string& name,
                                                      const std::string& text,
                                                      const SDL_Color& textColor,
                                                      const SDL_Color& bgColor,
                                                      const bool transparent) const
    {
      return ComponentFactory::createLabelPanel(
        name,
        text,
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/upcfb.ttf"),
          textColor.r, textColor.g, textColor.b, textColor.unused
        ),
        LabelContainer::Alignment::Left,
        bgColor,
        transparent
      );
    }

  }
}

#endif // UPGRADEINFO_HXX