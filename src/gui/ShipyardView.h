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

      private:

        void createView();

        void populateWithData(const core::Planet& planet, const core::Account& account) override;

        const std::string getShipCountFromType(const core::Ship::Type& type, const core::Planet& planet) const noexcept;

      private:

    };

    using ShipyardViewShPtr = std::shared_ptr<ShipyardView>;
  }
}

#include "ShipyardView.hxx"

#endif // SHIPYARDVIEW_H
