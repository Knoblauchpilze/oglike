#ifndef GALAXYPLAYERDATA_H
#define GALAXYPLAYERDATA_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "LabelContainer.h"

namespace ogame {
  namespace gui {

    class GalaxyPlayerData: public view::GraphicContainer
    {
      public:

        GalaxyPlayerData(const std::string& name);

        virtual ~GalaxyPlayerData();

        void populateWithPlayerData(/* TODO */);

      private:

        void createView();

        LabelContainerShPtr createLabelPanel(const std::string& name, const std::string& text, const SDL_Color& textColor) const;

      private:

    };

    using GalaxyPlayerDataShPtr = std::shared_ptr<GalaxyPlayerData>;
  }
}

#include "GalaxyPlayerData.hxx"

#endif // GALAXYPLAYERDATA_H
