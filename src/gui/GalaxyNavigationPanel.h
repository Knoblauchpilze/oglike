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
#include "ColoredFont.h"
#include "DataModelImplementation.h"

namespace ogame {
  namespace gui {

    class GalaxyNavigationPanel: public view::GraphicContainer, public player::GeneralActionListener
    {
      public:

        GalaxyNavigationPanel(const std::string& name,
                              const unsigned& galaxyCount,
                              const unsigned& systemCount,
                              player::GeneralDataModelShPtr model);

        virtual ~GalaxyNavigationPanel();

        void onActionTriggered(const player::GeneralDataModel& model) override;

        void populateWithSystemData(const core::System& system);

        void populateWithPlayerData(/* TODO */);

      private:

        void createView(const unsigned& galaxyCount,
                        const unsigned& systemCount,
                        player::GeneralDataModelShPtr model);

        LabelContainerShPtr createLabelPanel(const std::string& name,
                                             const std::string& text,
                                             view::ColoredFontShPtr font) const;

        ValueSelectorShPtr createValueSelector(const std::string& name,
                                               player::GeneralDataModel* model,
                                               view::ColoredFontShPtr font,
                                               const std::vector<std::string>& options) const;

        view::GraphicContainerShPtr createLabelForSystemView() const;

        void connectDataModel(player::GeneralDataModelShPtr model);

      private:

    };

    using GalaxyNavigationPanelShPtr = std::shared_ptr<GalaxyNavigationPanel>;
  }
}

#include "GalaxyNavigationPanel.hxx"

#endif // GALAXYNAVIGATIONPANEL_H
