#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "LabelContainer.h"

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

        void highlightView(const View& view);

      private:

        void createView();

        LabelContainerShPtr createLabelPanel(const View& name, const std::string& text) const;

        std::string getChildNameFromView(const View& view) const noexcept;

        void highlightViewPrivate(const View& view, const bool smartHighlight = true);

      private:

        View m_highlightedView;

    };

    using MenuViewShPtr = std::shared_ptr<MenuView>;
  }
}

#include "MenuView.hxx"

#endif // MENUVIEW_H
