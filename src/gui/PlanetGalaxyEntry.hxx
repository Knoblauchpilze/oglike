#ifndef PLANETGALAXYENTRY_HXX
#define PLANETGALAXYENTRY_HXX

#include "PlanetGalaxyEntry.h"

namespace ogame {
  namespace gui {

    inline
    PlanetIconDisplayShPtr PlanetGalaxyEntry::createPlanetIconPanel(const unsigned& count, const std::string& name) const {
      return std::make_shared<PlanetIconDisplay>(count, name);
    }

    inline
    PictureContainerShPtr PlanetGalaxyEntry::createPicturePanel(const std::string& name, const std::string& file) const {
      return std::make_shared<PictureContainer>(name, file);
    }

    inline
    LabelContainerShPtr PlanetGalaxyEntry::createLabelPanel(const std::string& name, const std::string& text, const SDL_Color& textColor) const {
      return std::make_shared<LabelContainer>(text, textColor, std::string("data/fonts/upcfb.ttf"), name);
    }

    inline
    SwitchPictureContainerShPtr PlanetGalaxyEntry::createSwitchPicture(const std::string& name, const std::string& onPicture, const std::string& offPicture) const {
      return std::make_shared<SwitchPictureContainer>(name, onPicture, offPicture);
    }

    inline
    view::GraphicContainerShPtr PlanetGalaxyEntry::createInformativePanel(const std::string& name) const {
      return std::make_shared<view::GraphicContainer>(name, view::utils::Area());
    }

    template <typename Type>
    inline
    bool PlanetGalaxyEntry::checkChild(const Type* child, const std::string& name) const noexcept {
      if (child == nullptr) {
        std::cerr << "[PLANET] Could not find " << name << " to update planet panel " << getName() << std::endl;
      }
      return child != nullptr;
    }

  }
}

#endif // PLANETGALAXYENTRY_HXX
