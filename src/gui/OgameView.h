#ifndef OGAMEVIEW_H
#define OGAMEVIEW_H

#include <memory>
#include <unordered_map>
#include <SDL/SDL.h>
#include "OgameAbstractView.h"
#include "GraphicContainer.h"

namespace ogame {
  namespace view {

    class OgameView: public OgameAbstractView
    {
      public:

        OgameView(const unsigned& width, const unsigned& height);
        
        virtual ~OgameView();

      private:

          void createViews(const float& margin);

      private:

        GraphicContainerShPtr m_panel;
        std::unordered_map<std::string, GraphicContainerShPtr> m_views;

    };

    using OgameViewShPtr = std::shared_ptr<OgameView>;
  }
}

//#include "OgameView.hxx"

#endif // OGAMEVIEW_H
