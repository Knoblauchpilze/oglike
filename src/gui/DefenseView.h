#ifndef DEFENSEVIEW_H
#define DEFENSEVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "Planet.h"
#include "DataModelImplementation.h"
#include "LabelledPicture.h"
#include "Defense.h"

namespace ogame {
  namespace gui {

    class DefenseView: public view::GraphicContainer, public player::GeneralActionListener
    {
      public:

        DefenseView(const std::string& name, player::GeneralDataModelShPtr model);

        virtual ~DefenseView();

        void onActionTriggered(const player::GeneralDataModel& model) override;

      private:

        void createView(player::GeneralDataModelShPtr model);

        void connectDataModel(player::GeneralDataModelShPtr dataModel);

        void populateWithPlanetData(const core::Planet& planet);

        LabelledPictureShPtr createLabelledPictureContainer(const std::string& name,
                                                            const std::string& picture,
                                                            const std::string& text) const;

        const std::string getDefenseCountFromType(const core::Defense::Type& type, const core::Planet& planet) const noexcept;

      private:

    };

    using DefenseViewShPtr = std::shared_ptr<DefenseView>;
  }
}

#include "DefenseView.hxx"

#endif // DEFENSEVIEW_H
