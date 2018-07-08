#ifndef RESOURCESVIEW_H
#define RESOURCESVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "LabelledPicture.h"
#include "Planet.h"

namespace ogame {
  namespace gui {

    class ResourcesView: public view::GraphicContainer
    {
      public:

        ResourcesView(const std::string& name);

        virtual ~ResourcesView();

        void populateWithPlanetData(const core::Planet& planet);

      private:

        void createView();

        LabelledPictureShPtr createResourcePanel(const std::string& name,
                                                 const float& value,
                                                 const std::string& resource) const;

      private:

    };

    using ResourcesViewShPtr = std::shared_ptr<ResourcesView>;
  }
}

#include "ResourcesView.hxx"

#endif // RESOURCESVIEW_H
