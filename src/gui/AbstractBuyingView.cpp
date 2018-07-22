
#include "AbstractBuyingView.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "PictureContainer.h"
#include "SelectorPanel.h"

namespace ogame {
  namespace gui {

    AbstractBuyingView::AbstractBuyingView(const std::string& name,
                                           player::GeneralDataModelShPtr model,
                                           const unsigned& gridWidth,
                                           const unsigned& gridHeight,
                                           const std::string& mainImageFile,
                                           const view::EventListener::Interaction::Mask& mask):
      view::GraphicContainer(name,
                             view::utils::Area()),
      player::GeneralActionListener(model.get()),
      view::GraphicContainerListener(),
      m_mask(mask),
      m_buyingAction(nullptr),
      m_activeBuyingActionName()
    {
      setBackgroundColor(SDL_Color{14, 57, 83, SDL_ALPHA_OPAQUE});

      createView(model, gridWidth, gridHeight, mainImageFile);
    }

    AbstractBuyingView::~AbstractBuyingView() {}

    void AbstractBuyingView::createView(player::GeneralDataModelShPtr model,
                                        const unsigned& gridWidth,
                                        const unsigned& gridHeight,
                                        const std::string& mainImageFile)
    {
      // Create the layout.
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(gridWidth, gridHeight, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create view ") + getName());
      }

      // Create the top container which will display either an image or the selected buying action.
      SelectorPanelShPtr selector = std::make_shared<SelectorPanel>(std::string("selector_panel"));

      // Create both the picture and the buying action.
      PictureContainerShPtr image = ComponentFactory::createPicturePanel(std::string("image_panel"), mainImageFile);
      m_buyingAction = std::make_shared<view::GraphicContainer>(std::string("buying_action"), view::utils::Area());

      // Check whether this container is valid.
      if (selector == nullptr ||
          image == nullptr ||
          m_buyingAction == nullptr)
      {
        throw GuiException(std::string("Could not allocate memory to create view") + getName());
      }

      // Register these components into the selector panel.
      selector->addChild(image);
      selector->addChild(m_buyingAction);

      // Assign the active child (image by default).
      selector->setActiveChild(std::string("image_panel"));

      // Add the selector panel to the layout.
      layout->addItem(selector, 0u, 0u, gridWidth, (gridHeight - 1u) / 2u);
      addChild(selector);

      // Assign the layout.
      setLayout(layout);
    }

  }
}
