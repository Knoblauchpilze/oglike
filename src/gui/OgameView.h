#ifndef OGAMEVIEW_H
#define OGAMEVIEW_H

#include <memory>
#include <unordered_map>
#include <SDL/SDL.h>
#include "OgameAbstractView.h"
#include "GraphicContainer.h"
#include "LinearLayout.h"

namespace ogame {
  namespace gui {

    class OgameView: public view::OgameAbstractView
    {
      public:

        OgameView(const unsigned& width,
                  const unsigned& height,
                  const unsigned& planetCount);
        
        virtual ~OgameView();

      private:

          void createViews(const float& margin, const unsigned& planetCount);

          void createGalaxyView(const unsigned& planetCount);

      private:

        view::GraphicContainerShPtr m_panel;
        std::unordered_map<std::string, view::GraphicContainerShPtr> m_views;

    };

    using OgameViewShPtr = std::shared_ptr<OgameView>;
  }
}

#endif // OGAMEVIEW_H
