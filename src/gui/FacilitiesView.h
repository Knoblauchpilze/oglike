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

      private:

        void createView(player::GeneralDataModelShPtr model);

        void connectDataModel(player::GeneralDataModelShPtr dataModel);

        void populateWithData(const core::Planet& planet, const core::Account& account) override;

        const std::string getDisplayForBuilding(const core::Building::Type& type, const core::Planet& planet) const noexcept;

      private:

    };

    using FacilitiesViewShPtr = std::shared_ptr<FacilitiesView>;
  }
}

#include "FacilitiesView.hxx"

#endif // FACILITIESVIEW_H
