#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "StateLabelContainer.h"
#include "DataModel.h"
#include "ActionListener.h"

namespace ogame {
  namespace gui {

    class MenuView: public view::GraphicContainer, public player::ActionListener
    {
      public:

        MenuView(const std::string& name, player::DataModel* model, const player::DataModel::View& initialView = player::DataModel::View::Overview);

        virtual ~MenuView();

        void onActionTriggered(const player::DataModel& model) override;

      private:

        void createView();

        StateLabelContainerShPtr createStateLabelPanel(const player::DataModel::View& view,
                                                       const std::string& text,
                                                       const StateContainer::StateAssociation& colors) const;

        std::string getChildNameFromView(const player::DataModel::View& view) const noexcept;

      private:

        player::DataModel::View m_highlightedView;

    };

    using MenuViewShPtr = std::shared_ptr<MenuView>;
  }
}

#include "MenuView.hxx"

#endif // MENUVIEW_H
