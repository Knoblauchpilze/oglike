#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "StateLabelContainer.h"
#include "DataModelImplementation.h"

namespace ogame {
  namespace gui {

    class MenuView: public view::GraphicContainer
    {
      public:

        MenuView(const std::string& name, player::GeneralDataModel* model, const player::View& initialView = player::View::Overview);

        virtual ~MenuView();

      private:

        void createView(player::GeneralDataModel* model);

        StateLabelContainerShPtr createStateLabelPanel(const player::View& view,
                                                       const std::string& text,
                                                       const StateContainer::StateAssociation& colors,
                                                       player::GeneralDataModel* model) const;

        std::string getChildNameFromView(const player::View& view) const noexcept;

      private:

    };

    using MenuViewShPtr = std::shared_ptr<MenuView>;
  }
}

#include "MenuView.hxx"

#endif // MENUVIEW_H
