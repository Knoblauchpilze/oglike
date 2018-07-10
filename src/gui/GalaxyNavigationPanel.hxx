#ifndef GALAXYNAVIGATIONPANEL_HXX
#define GALAXYNAVIGATIONPANEL_HXX

#include "GalaxyNavigationPanel.h"
#include "ComponentFactory.h"

namespace ogame {
  namespace gui {

    inline
    LabelContainerShPtr GalaxyNavigationPanel::createLabelPanel(const std::string& name,
                                                                const std::string& text,
                                                                view::ColoredFontShPtr font) const
    {
      return ComponentFactory::createLabelPanel(name, text, font);
    }

    inline
    ValueSelectorShPtr GalaxyNavigationPanel::createValueSelector(const std::string& name,
                                                                  view::ColoredFontShPtr font,
                                                                  const std::vector<std::string>& options) const
    {
      return ComponentFactory::createValueSelectorPanel(name, font, options);
    }

  }
}

#endif // GALAXYNAVIGATIONPANEL_HXX
