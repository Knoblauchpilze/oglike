#ifndef UPGRADERESOURCEINFO_HXX
#define UPGRADERESOURCEINFO_HXX

#include "UpgradeResourceInfo.h"
#include "ComponentFactory.h"
#include "FontFactory.h"
#include "GuiException.h"
#include "Research.h"
#include "Ship.h"
#include "Building.h"
#include "Defense.h"

namespace ogame {
  namespace gui {

    template <typename Element>
    inline
    void UpgradeResourceInfo::populateInformationFromElement(const Element& element) {
      throw GuiException(std::string("Cannot populate information panel from unknown element type"));
    }

    template <>
    inline
    void UpgradeResourceInfo::populateInformationFromElement(const core::Research& element) {
      std::cout << "[UPGRADE] Populating panel from research " << element.getName() << std::endl;
    }

    template <>
    inline
    void UpgradeResourceInfo::populateInformationFromElement(const core::Ship& element) {
      std::cout << "[UPGRADE] Populating panel from ship " << element.getName() << std::endl;
    }

    template <>
    inline
    void UpgradeResourceInfo::populateInformationFromElement(const core::Building& element) {
      std::cout << "[UPGRADE] Populating panel from building " << element.getName() << std::endl;
    }

    template <>
    inline
    void UpgradeResourceInfo::populateInformationFromElement(const core::Defense& element) {
      std::cout << "[UPGRADE] Populating panel from defense " << element.getName() << std::endl;
    }

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
        ),
        LabelContainer::Alignment::Left
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