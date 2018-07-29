#ifndef OPTIONSVIEW_H
#define OPTIONSVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "LabelContainer.h"
#include "Account.h"
#include "DataModelImplementation.h"

namespace ogame {
  namespace gui {

    class OptionsView: public view::GraphicContainer, public player::GeneralActionListener
    {
      public:

        OptionsView(const std::string& name, player::GeneralDataModel* model);

        virtual ~OptionsView();

        void onActionTriggered(const player::GeneralDataModel& model, const player::Action& action) override;

      private:

        void createView();

        LabelContainerShPtr createOptionPanel(const std::string& name, const std::string& text) const;

      private:

    };

    using OptionsViewShPtr = std::shared_ptr<OptionsView>;
  }
}

#include "OptionsView.hxx"

#endif // OPTIONSVIEW_H
