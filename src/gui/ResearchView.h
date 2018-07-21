#ifndef RESEARCHVIEW_H
#define RESEARCHVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "Planet.h"
#include "Account.h"
#include "Research.h"
#include "DataModelImplementation.h"
#include "LabelledPicture.h"

namespace ogame {
  namespace gui {

    class ResearchView: public view::GraphicContainer, public player::GeneralActionListener
    {
      public:

        ResearchView(const std::string& name, player::GeneralDataModelShPtr model);

        virtual ~ResearchView();

        void onActionTriggered(const player::GeneralDataModel& model) override;

      private:

        void createView(player::GeneralDataModelShPtr model);

        void connectDataModel(player::GeneralDataModelShPtr dataModel);

        void populateWithAccountData(const core::Account& account, const core::Planet& planet);

        LabelledPictureShPtr createLabelledPictureContainer(const std::string& name,
                                                            const std::string& picture,
                                                            const std::string& text) const;

        const std::string getDisplayForTech(const core::Research::Type& type, const core::Account& account) const noexcept;

      private:

    };

    using ResearchViewShPtr = std::shared_ptr<ResearchView>;
  }
}

#include "ResearchView.hxx"

#endif // RESEARCHVIEW_H
