#ifndef PLANETSVIEW_H
#define PLANETSVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "PlanetViewLink.h"
#include "Planet.h"
#include "DataModelImplementation.h"

namespace ogame {
  namespace gui {

    class PlanetsView: public view::GraphicContainer, public player::GeneralActionListener
    {
      public:

        PlanetsView(const std::string& name,
                    player::GeneralDataModel* model = nullptr,
                    const unsigned& planetCount = 15,
                    const std::vector<core::Planet>& planets = std::vector<core::Planet>());

        virtual ~PlanetsView();

        void onActionTriggered(const player::GeneralDataModel& model, const player::Action& action) override;

      private:

        void createView(const std::vector<core::Planet>& planets);

        PlanetViewLinkShPtr createPlanetView(const unsigned& index) const;

        PlanetViewLink* getOrCreatePlanetView(const unsigned& index);

        std::string computePlanetPanelNameFromIndex(const unsigned& index) const noexcept;

      private:

        unsigned m_planetCount;
        StateContainer::StateAssociation m_colors;

    };

    using PlanetsViewShPtr = std::shared_ptr<PlanetsView>;
  }
}

#include "PlanetsView.hxx"

#endif // PLANETSVIEW_H
