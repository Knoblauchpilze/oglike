#ifndef OPTIONSVIEW_H
#define OPTIONSVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "LabelContainer.h"
#include "Account.h"

namespace ogame {
  namespace gui {

    class OptionsView: public view::GraphicContainer
    {
      public:

        OptionsView(const std::string& name);

        virtual ~OptionsView();

        void populateWithPlayerData(const core::Account& account);

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
