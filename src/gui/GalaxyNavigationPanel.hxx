#ifndef GALAXYNAVIGATIONPANEL_HXX
#define GALAXYNAVIGATIONPANEL_HXX

#include "GalaxyNavigationPanel.h"
#include "ComponentFactory.h"

namespace ogame {
  namespace gui {

    inline
    void GalaxyNavigationPanel::onActionTriggered(const player::GeneralDataModel& model) {
      try {
        const core::System* activeSystem = model.getProperty<const core::System>(std::string("active_system"));
        populateWithSystemData(*activeSystem);
      }
      catch (const player::DataModelException& e) {
        std::cerr << "[NAVIGATIOn] Caught exception while setting up galaxy navigation panel:" << std::endl << e.what() << std::endl;
      }
    }

    inline
    LabelContainerShPtr GalaxyNavigationPanel::createLabelPanel(const std::string& name,
                                                                const std::string& text,
                                                                view::ColoredFontShPtr font) const
    {
      return ComponentFactory::createLabelPanel(name, text, font);
    }

    inline
    ValueSelectorShPtr GalaxyNavigationPanel::createValueSelector(const std::string& name,
                                                                  player::GeneralDataModel* model,
                                                                  view::ColoredFontShPtr font,
                                                                  const std::vector<std::string>& options) const
    {
      return ComponentFactory::createValueSelectorPanel(name, model, font, options);
    }

  }
}

#endif // GALAXYNAVIGATIONPANEL_HXX
