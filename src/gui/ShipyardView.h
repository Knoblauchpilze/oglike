#ifndef SHIPYARDVIEW_H
#define SHIPYARDVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "AbstractBuyingView.h"
#include "Ship.h"
#include "DataModelImplementation.h"

namespace ogame {
  namespace gui {

    class ShipyardView: public AbstractBuyingView
    {
      public:

        ShipyardView(const std::string& name, player::GeneralDataModelShPtr model);

        virtual ~ShipyardView();

      protected:

        void populateActionData(const std::string& origin, ElementDescriptionPanel& action) const override;

      private:

        void createView();

        void populateWithPlanetData(const core::Planet& planet) override;

        const std::string getShipCountFromType(const core::Ship::Type& type, const core::Planet& planet) const noexcept;

        const core::Ship::Type computeShipFromOriginNode(const std::string& origin) const noexcept;

      private:

    };

    using ShipyardViewShPtr = std::shared_ptr<ShipyardView>;
  }
}

#include "ShipyardView.hxx"

#endif // SHIPYARDVIEW_H
