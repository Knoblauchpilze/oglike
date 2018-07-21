#ifndef FLEETVIEW_H
#define FLEETVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "Planet.h"
#include "DataModelImplementation.h"
#include "LabelledPicture.h"

namespace ogame {
  namespace gui {

    class FleetView: public view::GraphicContainer, public player::GeneralActionListener
    {
      public:

        FleetView(const std::string& name, player::GeneralDataModelShPtr model);

        virtual ~FleetView();

        void onActionTriggered(const player::GeneralDataModel& model) override;

      private:

        void createView(player::GeneralDataModelShPtr model);

        void connectDataModel(player::GeneralDataModelShPtr dataModel);

        void populateWithPlanetData(const core::Planet& planet);

        LabelledPictureShPtr createLabelledPictureContainer(const std::string& name,
                                                            const std::string& picture,
                                                            const std::string& text) const;

      private:

    };

    using FleetViewShPtr = std::shared_ptr<FleetView>;
  }
}

#include "FleetView.hxx"

#endif // FLEETVIEW_H
