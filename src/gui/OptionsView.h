#ifndef OPTIONSVIEW_H
#define OPTIONSVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "LabelContainer.h"
#include "Account.h"
#include "ActionListener.h"
#include "DataModel.h"

namespace ogame {
  namespace gui {

    class OptionsView: public view::GraphicContainer, public player::ActionListener
    {
      public:

        OptionsView(const std::string& name, player::DataModel* model);

        virtual ~OptionsView();

        void onActionTriggered(const player::DataModel& model) override;

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
