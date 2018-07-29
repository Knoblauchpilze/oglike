#ifndef GALAXYVIEW_H
#define GALAXYVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "System.h"
#include "PlanetGalaxyEntry.h"
#include "DataModelImplementation.h"

namespace ogame {
  namespace gui {

    class GalaxyView: public view::GraphicContainer, public player::GeneralActionListener
    {
      public:

        GalaxyView(const std::string& name,
                   const unsigned& galaxyCount,
                   const unsigned& systemCount,
                   const unsigned& planetCount,
                   player::GeneralDataModelShPtr model);

        virtual ~GalaxyView();

        void onActionTriggered(const player::GeneralDataModel& model, const player::Action& action) override;

      private:

        void createView(const unsigned& navigationHeight,
                        const unsigned& galaxyCount,
                        const unsigned& systemCount,
                        const unsigned& planetCount,
                        player::GeneralDataModelShPtr model);

        void populateWithSystemData(const core::System& system);

        PlanetGalaxyEntryShPtr createPlanetPanel(const unsigned& planetIndex, const unsigned& planetCount) const;

        std::string getNameOfPlanetPanelFromIndex(const unsigned& planetIndex) const noexcept;

        void connectDataModel(player::GeneralDataModelShPtr dataModel);

      private:

    };

    using GalaxyViewShPtr = std::shared_ptr<GalaxyView>;
  }
}

#include "GalaxyView.hxx"

#endif // GALAXYVIEW_H
