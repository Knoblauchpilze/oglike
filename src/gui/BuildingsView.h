#ifndef BUILDINGSVIEW_H
#define BUILDINGSVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "AbstractBuyingView.h"
#include "Building.h"
#include "DataModelImplementation.h"

namespace ogame {
  namespace gui {

    class BuildingsView: public AbstractBuyingView
    {
      public:

        BuildingsView(const std::string& name, player::GeneralDataModelShPtr model);

        virtual ~BuildingsView();

      protected:

        void populateActionData(const std::string& origin, ElementDescriptionPanel& action) const override;

      private:

        void createView();

        void populateWithData(const core::Planet& planet, const core::Account& account) override;

        const std::string getDisplayForBuilding(const core::Building::Type& type, const core::Planet& planet) const noexcept;

        const core::Building::Type computeBuildingFromOriginNode(const std::string& origin) const noexcept;

        const std::string getPictureNameFromBuilding(const core::Building::Type& type, const bool reduced = true) const noexcept;

      private:

    };

    using BuildingsViewShPtr = std::shared_ptr<BuildingsView>;
  }
}

#include "BuildingsView.hxx"

#endif // BUILDINGSVIEW_H
