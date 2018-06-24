#ifndef GALAXYVIEW_H
#define GALAXYVIEW_H

#include <memory>
#include <unordered_map>
#include <SDL/SDL.h>
#include "GraphicContainer.h"

namespace ogame {
  namespace gui {

    class GalaxyView: public view::GraphicContainer
    {
      public:

        GalaxyView(const unsigned& width, const unsigned& height);
        
        virtual ~GalaxyView();

      private:

    };

    using GalaxyViewShPtr = std::shared_ptr<GalaxyView>;
  }
}

#endif // GALAXYVIEW_H
