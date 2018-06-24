
#include "PlanetGalaxyEntry.h"
#include "GridLayout.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    PlanetGalaxyEntry::PlanetGalaxyEntry(const unsigned& index):
      view::GraphicContainer(std::string("Planet ") + std::to_string(index) + " view",
                             view::utils::Area(),
                             view::EventListener::Interaction::NoInteraction,
                             nullptr)
    {
      createView();
    }

    PlanetGalaxyEntry::~PlanetGalaxyEntry() {}

    void PlanetGalaxyEntry::createView() {
      // Create the main layout for this panel.
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(11u, 1u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create planet's panel"));
      }

      // Add each informative panel to the layout and as child of this panel.
      view::GraphicContainerShPtr icon = createInformativePanel(std::string("Planet icon"));
      view::GraphicContainerShPtr name = createInformativePanel(std::string("Planet name"));
      view::GraphicContainerShPtr wreckField = createInformativePanel(std::string("Planet wreck field"));
      view::GraphicContainerShPtr moon = createInformativePanel(std::string("Planet moon"));
      view::GraphicContainerShPtr owner = createInformativePanel(std::string("Planet owner's name"));
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
      addChild(wreckField);
      layout->addItem(wreckField, 4u, 1u, 1u, 1u);
      addChild(moon);
      layout->addItem(moon,       5u, 0u, 1u, 1u);
      addChild(owner);
      layout->addItem(owner,      6u, 0u, 3u, 1u);
      addChild(actions);
      layout->addItem(actions,    9u, 0u, 2u, 1u);

      // Now assign the layout to this container.
      setLayout(layout);
    }

    view::GraphicContainerShPtr PlanetGalaxyEntry::createInformativePanel(const std::string& name) {
      return std::make_shared<view::GraphicContainer>(
        name,
        view::utils::Area(),
        view::EventListener::Interaction::NoInteraction
      );
    }

  }
}
