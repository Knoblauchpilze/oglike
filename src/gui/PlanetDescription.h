#ifndef PLANETDESCRIPTION_H
#define PLANETDESCRIPTION_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "Planet.h"
#include "DataModelImplementation.h"
#include "LabelContainer.h"
#include "LabelledPicture.h"

namespace ogame {
  namespace gui {

    class PlanetDescription: public view::GraphicContainer, public player::GeneralActionListener
    {
      public:

        PlanetDescription(const std::string& name, player::GeneralDataModelShPtr model);

        virtual ~PlanetDescription();

        void onActionTriggered(const player::GeneralDataModel& model, const player::Action& action) override;

      private:

        void createView();

        void connectDataModel(player::GeneralDataModelShPtr dataModel);

        void populateWithPlanetData(const core::Planet& planet);

        LabelContainerShPtr createInfoLabelPanel(const std::string& name, const std::string& text) const;

        LabelContainerShPtr createValueLabelPanel(const std::string& name, const std::string& text) const;

        LabelContainerShPtr createLabelPanel(const std::string& name,
                                             const std::string& text,
                                             const int& red,
                                             const int& green,
                                             const int& blue,
                                             const int& alpha,
                                             const LabelContainer::Alignment& alignment) const;

        LabelledPictureShPtr createLabelledPicturePanel(const std::string& name,
                                                        const std::string& picture,
                                                        const std::string& text) const;

      private:

    };

    using PlanetDescriptionShPtr = std::shared_ptr<PlanetDescription>;
  }
}

#include "PlanetDescription.hxx"

#endif // PLANETDESCRIPTION_H
