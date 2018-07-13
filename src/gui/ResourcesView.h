#ifndef RESOURCESVIEW_H
#define RESOURCESVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "LabelledPicture.h"
#include "Planet.h"
#include "ActionListener.h"
#include "DataModel.h"

namespace ogame {
  namespace gui {

    class ResourcesView: public view::GraphicContainer, public player::ActionListener
    {
      public:

        ResourcesView(const std::string& name, player::DataModel* model);

        virtual ~ResourcesView();

        void onActionTriggered(const player::DataModel& model);

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
