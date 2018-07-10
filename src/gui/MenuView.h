#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "StateLabelContainer.h"

namespace ogame {
  namespace gui {

    class MenuView: public view::GraphicContainer
    {
      public:

        enum class View {
          Overview,
          Resources,
          Facilities,
          Research,
          Shipyard,
          Defense,
          Fleet,
          Galaxy,
          Alliance
        };

        MenuView(const std::string& name, const View& initialView = View::Overview);

        virtual ~MenuView();

      private:

        void createView();

        StateLabelContainerShPtr createStateLabelPanel(const View& view,
                                                       const std::string& text,
                                                       const StateContainer::StateAssociation& colors) const;

        std::string getChildNameFromView(const View& view) const noexcept;

      private:

        View m_highlightedView;

    };

    using MenuViewShPtr = std::shared_ptr<MenuView>;
  }
}

#include "MenuView.hxx"

#endif // MENUVIEW_H
