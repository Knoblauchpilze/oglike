#ifndef UPGRADERESOURCEINFO_HXX
#define UPGRADERESOURCEINFO_HXX

#include "UpgradeResourceInfo.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    inline
    LabelContainerShPtr UpgradeResourceInfo::createLabelPanel(const std::string& name,
                                                              const std::string& text,
                                                              const SDL_Color& color) const
    {
      return ComponentFactory::createLabelPanel(
        name,
        text,
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/upcfb.ttf"),
          color.r, color.g, color.b, color.unused
        )
      );
    }

    inline
    LabelledPictureShPtr UpgradeResourceInfo::createLabelledPicturePanel(const std::string& name,
                                                                         const std::string& picture,
                                                                         const std::string& text) const
    {
      return ComponentFactory::createLabelledPicturePanel(
        name,
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/times.ttf"),
          255, 255, 255, SDL_ALPHA_OPAQUE
        ),
        picture,
        text,
        LabelledPicture::Alignment::Above
      );
    }

  }
}

#endif // UPGRADERESOURCEINFO_HXX