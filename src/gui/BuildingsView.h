#ifndef BUILDINGSVIEW_H
#define BUILDINGSVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "Planet.h"
#include "DataModelImplementation.h"
#include "LabelledPicture.h"

namespace ogame {
  namespace gui {

    class BuildingsView: public view::GraphicContainer, public player::GeneralActionListener
    {
      public:

        BuildingsView(const std::string& name, player::GeneralDataModelShPtr model);

        virtual ~BuildingsView();

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

    using BuildingsViewShPtr = std::shared_ptr<BuildingsView>;
  }
}

#include "BuildingsView.hxx"

#endif // BUILDINGSVIEW_H
