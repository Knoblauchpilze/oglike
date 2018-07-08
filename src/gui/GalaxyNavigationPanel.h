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
#include "Font.h"

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

        void populateWithPlayerData(/* TODO */);

      private:

        void createView(const unsigned& galaxyCount, const unsigned& systemCount);

        LabelContainerShPtr createLabelPanel(const std::string& name,
                                             const std::string& text,
                                             view::FontShPtr font) const;

        ValueSelectorShPtr createValueSelector(const std::string& name,
                                               view::FontShPtr font,
                                               const std::vector<std::string>& options) const;

        view::GraphicContainerShPtr createLabelForSystemView() const;

      private:

        view::FontShPtr m_labelFont;
        view::FontShPtr m_selectorFont;
        view::FontShPtr m_infoFont;

    };

    using GalaxyNavigationPanelShPtr = std::shared_ptr<GalaxyNavigationPanel>;
  }
}

#include "GalaxyNavigationPanel.hxx"

#endif // GALAXYNAVIGATIONPANEL_H
