#ifndef FLEETVIEW_H
#define FLEETVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "DataModelImplementation.h"
#include "LabelledPicture.h"
#include "Ship.h"

namespace ogame {
  namespace gui {

    class FleetView: public view::GraphicContainer, public player::GeneralActionListener
    {
      public:

        FleetView(const std::string& name, player::GeneralDataModelShPtr model);

        virtual ~FleetView();

        void onActionTriggered(const player::GeneralDataModel& model, const player::Action& action) override;

      private:

        void createView();

        void populateWithPlanetData(const core::Planet& planet);

        const std::string getShipCountFromType(const core::Ship::Type& type, const core::Planet& planet) const noexcept;

        const core::Ship::Type computeShipFromOriginNode(const std::string& origin) const noexcept;

        const std::string getPictureNameFromShip(const core::Ship::Type& type, const bool reduced = true) const noexcept;

        LabelledPictureShPtr createLabelledPictureContainer(const std::string& name,
                                                            const std::string& picture,
                                                            const std::string& text);

      private:

    };

    using FleetViewShPtr = std::shared_ptr<FleetView>;
  }
}

#include "FleetView.hxx"

#endif // FLEETVIEW_H
