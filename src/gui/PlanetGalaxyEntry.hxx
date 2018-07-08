#ifndef PLANETGALAXYENTRY_HXX
#define PLANETGALAXYENTRY_HXX

#include "PlanetGalaxyEntry.h"
#include "ComponentFactory.h"

namespace ogame {
  namespace gui {

    inline
    PlanetIconDisplayShPtr PlanetGalaxyEntry::createPlanetIconPanel(const unsigned& count, const std::string& name) const {
      return std::make_shared<PlanetIconDisplay>(count, name);
    }

    inline
    LabelContainerShPtr PlanetGalaxyEntry::createLabelPanel(const std::string& name, const std::string& text, view::FontShPtr font) const {
      return ComponentFactory::createLabelPanel(
        name,
        text,
        font,
        font
      );
    }

    inline
    SwitchPictureContainerShPtr PlanetGalaxyEntry::createSwitchPicture(const std::string& name, const std::string& onPicture, const std::string& offPicture) const {
      return ComponentFactory::createSwitchPicturePanel(name, onPicture, offPicture);
    }

    inline
    PlanetActionListShPtr PlanetGalaxyEntry::createActionList(const std::string& name) const {
      return std::make_shared<PlanetActionList>(name);
    }

  }
}

#endif // PLANETGALAXYENTRY_HXX
