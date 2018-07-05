#ifndef GALAXYNAVIGATIONPANEL_H
#define GALAXYNAVIGATIONPANEL_H

#include <memory>
#include <vector>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "PictureContainer.h"
#include "LabelContainer.h"
#include "SwitchPictureContainer.h"
#include "ValueSelector.h"
#include "System.h"

namespace ogame {
  namespace gui {

    class GalaxyNavigationPanel: public view::GraphicContainer
    {
      public:

        GalaxyNavigationPanel(const std::string& name,
                              const unsigned& galaxyCount,
                              const unsigned& systemCount);

        virtual ~GalaxyNavigationPanel();

        void populateWithSystemData(const core::System& system);

      private:

        void createView(const unsigned& galaxyCount, const unsigned& systemCount);

        LabelContainerShPtr createLabelPanel(const std::string& name, const std::string& text, const SDL_Color& textColor) const;

        ValueSelectorShPtr createValueSelector(const std::string& name, const SDL_Color& optionsColor, const std::vector<std::string>& options) const;

        view::GraphicContainerShPtr createLabelForSystemView() const;

      private:

    };

    using GalaxyNavigationPanelShPtr = std::shared_ptr<GalaxyNavigationPanel>;
  }
}

#include "GalaxyNavigationPanel.hxx"

#endif // GALAXYNAVIGATIONPANEL_H