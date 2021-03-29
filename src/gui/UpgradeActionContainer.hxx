#ifndef UPGRADEACTIONCONTAINER_HXX
#define UPGRADEACTIONCONTAINER_HXX

#include "UpgradeActionContainer.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    inline
    LabelContainerShPtr UpgradeActionContainer::createLabel(const std::string& name,
                                                            const std::string& text,
                                                            const SDL_Color& textColor,
                                                            const LabelContainer::Alignment& alignment,
                                                            const SDL_Color& bgColor,
                                                            const bool transparent,
                                                            const int& policeSize) const
    {
      return ComponentFactory::createLabelPanel(
        name,
        text,
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/tahomabd.ttf"),
          textColor.r, textColor.g, textColor.b, textColor.unused,
          policeSize
        ),
        alignment,
        bgColor,
        transparent
      );
    }

    inline
    PhotoGalleryShPtr UpgradeActionContainer::createPhotoGallery(const std::string& name,
                                                                 const unsigned& picturesCount) const
    {
      return ComponentFactory::createPhotoGalleryPanel(
        name,
        picturesCount
      );
    }

    inline
    const std::string UpgradeActionContainer::computeDisplayTime(const float& seconds) const {
      // Compute values up to a year.
      const int uSeconds = static_cast<int>(seconds);
      const int years =   uSeconds / (60 * 60 * 24 * 7 * 52);
      const int weeks =   uSeconds / (60 * 60 * 24 * 7)         -     years * 52;
      const int days =    uSeconds / (60 * 60 * 24)             -    (years * 52 + weeks) * 7;
      const int hours =   uSeconds / (60 * 60)                  -   ((years * 52 + weeks) * 7 + days) * 24;
      const int minutes = uSeconds / (60)                       -  (((years * 52 + weeks) * 7 + days) * 24 + hours) * 60;
      const int realSec = uSeconds                              - ((((years * 52 + weeks) * 7 + days) * 24 + hours) * 60 + minutes) * 60;

      // Build the final string.
      std::string duration;
      if (std::abs(years) > 0) {
        duration += (std::to_string(years) + "y ");
      }
      if (std::abs(weeks) > 0) {
        duration += (std::to_string(weeks) + "w ");
      }
      if (std::abs(days) > 0) {
        duration += (std::to_string(days) + "d ");
      }
      if (std::abs(hours) > 0) {
        duration += (std::to_string(hours) + "h ");
      }
      if (std::abs(minutes) > 0) {
        duration += (std::to_string(minutes) + "m ");
      }
      if (std::abs(realSec) > 0) {
        duration += (std::to_string(realSec) + "s");
      }

      return duration;
    }

  }
}

#endif // UPGRADEACTIONCONTAINER_HX