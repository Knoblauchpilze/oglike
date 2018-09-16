#ifndef FACILITIESVIEW_H
#define FACILITIESVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "AbstractBuyingView.h"
#include "Building.h"
#include "DataModelImplementation.h"

namespace ogame {
  namespace gui {

    class FacilitiesView: public AbstractBuyingView
    {
      public:

        FacilitiesView(const std::string& name, player::GeneralDataModelShPtr model);

        virtual ~FacilitiesView();

      protected:

        void populateActionData(const std::string& origin, ElementDescriptionPanel& action) const override;

      private:

        void createView();

        void populateWithPlanetData(const core::Planet& planet) override;

        const std::string getDisplayForBuilding(const core::Building::Type& type, const core::Planet& planet) const noexcept;

        const core::Building::Type computeBuildingFromOriginNode(const std::string& origin) const noexcept;

      private:

    };

    using FacilitiesViewShPtr = std::shared_ptr<FacilitiesView>;
  }
}

#include "FacilitiesView.hxx"

#endif // FACILITIESVIEW_H
