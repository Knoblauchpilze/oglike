#ifndef SHIPYARDVIEW_H
#define SHIPYARDVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "Planet.h"
#include "DataModelImplementation.h"
#include "LabelledPicture.h"

namespace ogame {
  namespace gui {

    class ShipyardView: public view::GraphicContainer, public player::GeneralActionListener
    {
      public:

        ShipyardView(const std::string& name, player::GeneralDataModelShPtr model);

        virtual ~ShipyardView();

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

    using ShipyardViewShPtr = std::shared_ptr<ShipyardView>;
  }
}

#include "ShipyardView.hxx"

#endif // SHIPYARDVIEW_H
