#ifndef GALAXYNAVIGATIONPANEL_HXX
#define GALAXYNAVIGATIONPANEL_HXX

#include "GalaxyNavigationPanel.h"
#include "ComponentFactory.h"

namespace ogame {
  namespace gui {

    inline
    LabelContainerShPtr GalaxyNavigationPanel::createLabelPanel(const std::string& name, const std::string& text, const SDL_Color& textColor) const {
      return ComponentFactory::createLabelPanel(name, text, std::string("data/fonts/ARLRDBD.ttf"), textColor, 20);
    }

    inline
    ValueSelectorShPtr GalaxyNavigationPanel::createValueSelector(const std::string& name, const SDL_Color& optionsColor, const std::vector<std::string>& options) const {
      return ComponentFactory::createValueSelectorPanel(name, std::string("data/fonts/ARLRDBD.ttf"), optionsColor, options);
    }

  }
}

#endif // GALAXYNAVIGATIONPANEL_HXX
