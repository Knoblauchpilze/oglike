#ifndef OVERVIEW_H
#define OVERVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "Planet.h"
#include "DataModelImplementation.h"

namespace ogame {
  namespace gui {

    class OverView: public view::GraphicContainer, public player::GeneralActionListener
    {
      public:

        OverView(const std::string& name, player::GeneralDataModelShPtr model);

        virtual ~OverView();

        void onActionTriggered(const player::GeneralDataModel& model) override;

      private:

        void createView();

        void connectDataModel(player::GeneralDataModelShPtr dataModel);

        void populateWithPlanetData(const core::Planet& planet);

      private:

    };

    using OverViewShPtr = std::shared_ptr<OverView>;
  }
}

#include "Overview.hxx"

#endif // OVERVIEW_H
