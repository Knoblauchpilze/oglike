#ifndef OVERVIEW_H
#define OVERVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "PictureContainer.h"
#include "Planet.h"
#include "DataModelImplementation.h"

namespace ogame {
  namespace gui {

    class OverView: public PictureContainer, public player::GeneralActionListener
    {
      public:

        OverView(const std::string& name, player::GeneralDataModelShPtr model);

        virtual ~OverView();

        void onActionTriggered(const player::GeneralDataModel& model) override;

      private:

        void createView(player::GeneralDataModelShPtr model);

        void connectDataModel(player::GeneralDataModelShPtr dataModel);

        void populateWithPlanetData(const core::Planet& planet);

        void populateWithAccountData(const core::Account& account);

      private:

    };

    using OverViewShPtr = std::shared_ptr<OverView>;
  }
}

#include "Overview.hxx"

#endif // OVERVIEW_H
