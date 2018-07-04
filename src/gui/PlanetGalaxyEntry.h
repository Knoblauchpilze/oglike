#ifndef PLANETGALAXYENTRY_H
#define PLANETGALAXYENTRY_H

#include <memory>
#include <vector>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "Planet.h"
#include "PictureContainer.h"
#include "LabelContainer.h"
#include "PlanetIconDisplay.h"
#include "SwitchPictureContainer.h"
#include "PlanetActionList.h"

namespace ogame {
  namespace gui {

    class PlanetGalaxyEntry: public view::GraphicContainer
    {
      public:

        PlanetGalaxyEntry(const unsigned& index, const unsigned& count, const std::string& name);
        
        virtual ~PlanetGalaxyEntry();

        void populateWithPlanetData(const core::Planet& planet);

      private:

        void createView(const unsigned& index, const unsigned& count);

        PlanetIconDisplayShPtr createPlanetIconPanel(const unsigned& count, const std::string& name) const;

        PictureContainerShPtr createPicturePanel(const std::string& name, const std::string& file) const;

        LabelContainerShPtr createLabelPanel(const std::string& name, const std::string& text, const SDL_Color& textColor) const;

        SwitchPictureContainerShPtr createSwitchPicture(const std::string& name, const std::string& onPicture, const std::string& offPicture) const;

        PlanetActionListShPtr createActionList(const std::string& name) const;

        view::GraphicContainerShPtr createInformativePanel(const std::string& name) const;

      private:

    };

    using PlanetGalaxyEntryShPtr = std::shared_ptr<PlanetGalaxyEntry>;
  }
}

#include "PlanetGalaxyEntry.hxx"

#endif // PLANETGALAXYENTRY_H
