
#include "PlanetGalaxyEntry.h"
#include "GridLayout.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    PlanetGalaxyEntry::PlanetGalaxyEntry(const unsigned& count, const std::string& name):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::NoInteraction,
                             nullptr)
    {
      // Assign the background color.
      setBackgroundColor({14, 57, 83, SDL_ALPHA_OPAQUE});

      createView(count);
    }

    PlanetGalaxyEntry::~PlanetGalaxyEntry() {}

    void PlanetGalaxyEntry::populateWithPlanetData(const core::Planet& planet) {
      lock();

      // Update information.
      PlanetIconDisplay* icon = getChild<PlanetIconDisplay*>(std::string("Planet icon"));
      if (checkChild(icon, std::string("Planet icon"))) {
        icon->populateWithPlanetData(planet);
      }
      LabelContainer* label = getChild<LabelContainer*>(std::string("Planet name"));
      if (checkChild(label, std::string("Planet name"))) {
        label->setText(planet.isColonized() ? planet.getName() : "");
      }
      SwitchPictureContainer* moon = getChild<SwitchPictureContainer*>(std::string("Planet moon"));
      if (checkChild(moon, std::string("Planet moon"))) {
        moon->updateStatus(planet.hasMoon());
      }
      SwitchPictureContainer* wreckfield = getChild<SwitchPictureContainer*>(std::string("Planet wreck field"));
      if (checkChild(wreckfield, std::string("Planet wreck field"))) {
        wreckfield->updateStatus(planet.hasWreckfield());
      }
      LabelContainer* owner = getChild<LabelContainer*>(std::string("Planet owner's name"));
      if (checkChild(label, std::string("Planet owner's name"))) {
        owner->setText(planet.isColonized() ? "Colonized" : "");
      }

      // Make this component dirty.
      makeDeepDirty();

      unlock();
    }

    void PlanetGalaxyEntry::createView(const unsigned& count) {
      // Create the main layout for this panel.
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(11u, 1u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create planet's panel"));
      }

      // Add each informative panel to the layout and as child of this panel.
      PlanetIconDisplayShPtr icon = createPlanetIconPanel(count, std::string("Planet icon"));
      LabelContainerShPtr name = createLabelPanel(std::string("Planet name"),
                                                  std::string("Not available"),
                                                  {128, 0, 0, SDL_ALPHA_OPAQUE});
      SwitchPictureContainerShPtr wreckField = createSwitchPicture(std::string("Planet wreck field"), 
                                                                   std::string("data/img/wreckfield.bmp"),
                                                                   std::string("data/img/wreckfield_none.bmp"));
      SwitchPictureContainerShPtr moon = createSwitchPicture(std::string("Planet moon"), 
                                                             std::string("data/img/moon.bmp"),
                                                             std::string("data/img/moon_none.bmp"));
      LabelContainerShPtr owner = createLabelPanel(std::string("Planet owner's name"),
                                                           std::string("Not available"),
                                                           {255, 0, 0, SDL_ALPHA_OPAQUE});
      view::GraphicContainerShPtr actions = createInformativePanel(std::string("Planet actions"));
      if (icon == nullptr ||
          name == nullptr ||
          wreckField == nullptr ||
          moon == nullptr ||
          owner == nullptr ||
          actions == nullptr)
      {
        throw GuiException(std::string("Could not allocate one of the informative panel for planet's panel"));
      }

      addChild(icon);
      layout->addItem(icon,       0u, 0u, 1u, 1u);
      addChild(name);
      layout->addItem(name,       1u, 0u, 3u, 1u);
      addChild(moon);
      layout->addItem(moon,       4u, 0u, 1u, 1u);
      addChild(wreckField);
      layout->addItem(wreckField, 5u, 0u, 1u, 1u);
      addChild(owner);
      layout->addItem(owner,      6u, 0u, 3u, 1u);
      addChild(actions);
      layout->addItem(actions,    9u, 0u, 2u, 1u);

      // Now assign the layout to this container.
      setLayout(layout);
    }

  }
}
