#ifndef FLEETVIEW_H
#define FLEETVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "AbstractBuyingView.h"
#include "Ship.h"
#include "DataModelImplementation.h"

namespace ogame {
  namespace gui {

    class FleetView: public AbstractBuyingView
    {
      public:

        FleetView(const std::string& name, player::GeneralDataModelShPtr model);

        virtual ~FleetView();

      private:

        void createView();

        void populateWithData(const core::Planet& planet, const core::Account& account) override;

        const std::string getShipCountFromType(const core::Ship::Type& type, const core::Planet& planet) const noexcept;

      private:

    };

    using FleetViewShPtr = std::shared_ptr<FleetView>;
  }
}

#include "FleetView.hxx"

#endif // FLEETVIEW_H
