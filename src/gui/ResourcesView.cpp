
#include "ResourcesView.h"
#include "GuiException.h"
#include "LabelledPicture.h"

namespace ogame {
  namespace gui {

    ResourcesView::ResourcesView(const std::string& name):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::NoInteraction,
                             std::make_shared<view::LinearLayout>(
                               view::LinearLayout::Direction::Horizontal,
                               0.0f,
                               20.0f,
                               this
                             ))
    {
      setBackgroundColor({14, 57, 83, SDL_ALPHA_OPAQUE});

      createView();
    }

    ResourcesView::~ResourcesView() {}

    void ResourcesView::populateWithPlanetData(const core::Planet& planet) {
      lock();

      // Update each resource.
      LabelledPicture* metal = getChild<LabelledPicture*>(std::string("metal_resource_panel"));
      if (checkChild(metal, std::string("Metal resource panel"))) {
        metal->setLabel(std::to_string(200));
      }
      LabelledPicture* cristal = getChild<LabelledPicture*>(std::string("cristal_resource_panel"));
      if (checkChild(cristal, std::string("Cristal resource panel"))) {
        cristal->setLabel(std::to_string(2000));
      }
      LabelledPicture* deut = getChild<LabelledPicture*>(std::string("deuterium_resource_panel"));
      if (checkChild(deut, std::string("Deuterium resource panel"))) {
        deut->setLabel(std::to_string(20000));
      }
      LabelledPicture* antimatter = getChild<LabelledPicture*>(std::string("antimatter_resource_panel"));
      if (checkChild(antimatter, std::string("Antimatter resource panel"))) {
        antimatter->setLabel(std::to_string(200000));
      }
      LabelledPicture* energy = getChild<LabelledPicture*>(std::string("energy_resource_panel"));
      if (checkChild(energy, std::string("Energy resource panel"))) {
        energy->setLabel(std::to_string(2000000));
      }

      makeDeepDirty();
      unlock();
    }

    void ResourcesView::createView() {
      // Create all the resources.
      LabelledPictureShPtr metal = createResourcePanel(std::string("metal_resource_panel"), 0.0f, std::string("metal"));

      LabelledPictureShPtr cristal = createResourcePanel(std::string("cristal_resource_panel"), 0.0f, std::string("cristal"));

      LabelledPictureShPtr deuterium = createResourcePanel(std::string("deuterium_resource_panel"), 0.0f, std::string("deuterium"));

      LabelledPictureShPtr antimatter = createResourcePanel(std::string("antimatter_resource_panel"), 0.0f, std::string("antimatter"));

      LabelledPictureShPtr energy = createResourcePanel(std::string("energy_resource_panel"), 0.0f, std::string("energy"));

      if (metal == nullptr ||
          cristal == nullptr ||
          deuterium == nullptr ||
          antimatter == nullptr ||
          energy == nullptr)
      {
        throw GuiException(std::string("Could not create one or more component for ") + getName());
      }

      addChild(metal);
      addChild(cristal);
      addChild(deuterium);
      addChild(antimatter);
      addChild(energy);
    }

  }
}
