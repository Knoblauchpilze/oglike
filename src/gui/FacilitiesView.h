#ifndef FACILITIESVIEW_H
#define FACILITIESVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "Planet.h"
#include "DataModelImplementation.h"
#include "LabelledPicture.h"

namespace ogame {
  namespace gui {

    class FacilitiesView: public view::GraphicContainer, public player::GeneralActionListener
    {
      public:

        FacilitiesView(const std::string& name, player::GeneralDataModelShPtr model);

        virtual ~FacilitiesView();

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

    using FacilitiesViewShPtr = std::shared_ptr<FacilitiesView>;
  }
}

#include "FacilitiesView.hxx"

#endif // FACILITIESVIEW_H
