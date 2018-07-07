#ifndef GALAXYPLAYERDATA_HXX
#define GALAXYPLAYERDATA_HXX

#include "GalaxyPlayerData.h"
#include "ComponentFactory.h"

namespace ogame {
  namespace gui {

    inline
    LabelContainerShPtr GalaxyPlayerData::createLabelPanel(const std::string& name, const std::string& text, const SDL_Color& textColor) const {
      return ComponentFactory::createLabelPanel(
        name,
        text,
        std::string("data/fonts/angsa.ttf"),
        textColor,
        25
      );
    }

  }
}

#endif // GALAXYPLAYERDATA_HXX
