#ifndef ELEMENTDESCRIPTIONPANEL_HXX
#define ELEMENTDESCRIPTIONPANEL_HXX

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "GuiException.h"
#include "Research.h"
#include "Ship.h"
#include "Building.h"
#include "PictureContainer.h"

namespace ogame {
  namespace gui {

    inline
    void ElementDescriptionPanel::setImagePath(const std::string& path) {
      lock();

      PictureContainer* image = getChild<PictureContainer*>(std::string("image_panel"));
      if (checkChild(image, std::string("Element description image panel"))) {
        std::cout << "[ELEMENT] Setting image path " << path << " for " << getName() << ", img=" << image->getName() << std::endl;
        image->setImagePath(path);
      }

      unlock();
    }

    template <typename Element>
    inline
    void ElementDescriptionPanel::populateInformationFromElement(const Element& element) {
      throw GuiException(std::string("Cannot populate information panel from unknown element type"));
    }

    template <>
    inline
    void ElementDescriptionPanel::populateInformationFromElement(const core::Research& element) {
      std::cout << "[ELEMENT] Populating panel from research" << std::endl;
    }

    template <>
    inline
    void ElementDescriptionPanel::populateInformationFromElement(const core::Ship& element) {
      std::cout << "[ELEMENT] Populating panel from ship" << std::endl;
    }

    template <>
    inline
    void ElementDescriptionPanel::populateInformationFromElement(const core::Building& element) {
      std::cout << "[ELEMENT] Populating panel from building" << std::endl;
    }

  }
}

#endif // ELEMENTDESCRIPTIONPANEL_HXX