
#include "OgameView.h"
#include "GuiException.h"
#include "GridLayout.h"
#include "ComponentFactory.h"

namespace ogame {
  namespace gui {

    OgameView::OgameView(const unsigned& width,
                         const unsigned& height,
                         const unsigned& galaxyCount,
                         const unsigned& systemCount,
                         const unsigned& planetCount,
                         player::GeneralDataModelShPtr dataModel):
      OgameAbstractView(std::string("Ogame is life and ya know it !"),
                        std::string("data/icon.bmp"),
                        width,
                        height),
      player::GeneralActionListener(dataModel.get()),

      m_panel(nullptr),

      m_menuView(nullptr),
      m_optionsView(nullptr),
      m_resourcesView(nullptr),
      m_planetsView(nullptr),
      m_generalView(nullptr),

      m_overView(nullptr),
      m_buildingsView(nullptr),
      m_facilitiesView(nullptr),
      m_researchView(nullptr),
      m_shipyardView(nullptr),
      m_defenseView(nullptr),
      m_fleetView(nullptr),
      m_galaxyView(nullptr),
      m_allianceView(nullptr)
    {
      // Create views.
      createViews(1.0f, galaxyCount, systemCount, planetCount, dataModel);

      // Connect the data model.
      connectDataModel(dataModel);
    }

    OgameView::~OgameView() {
      // Nothing to do.
    }

    void OgameView::createViews(const float& margin,
                                const unsigned& galaxyCount,
                                const unsigned& systemCount,
                                const unsigned& planetCount,
                                player::GeneralDataModelShPtr model)
    {
      // Create the main panel.
      createMainPanel(margin);

      // Create the main layout: left and right views and the general view.
      createMainLayout(model);

      // Create thematic views.
      createThematicViews(galaxyCount, systemCount, planetCount, model);
    }

    void OgameView::createMainLayout(player::GeneralDataModelShPtr model) {
      // Create the layout for the main panel.
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(12u, 12u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not create main panel layout used for display"));
      }

      // Create each view.
      m_optionsView     = std::make_shared<OptionsView>(std::string("options_view"), model.get());
      m_menuView        = std::make_shared<MenuView>(std::string("menu_view"), model.get());
      m_resourcesView   = std::make_shared<ResourcesView>(std::string("resources_view"), model.get());
      m_planetsView     = std::make_shared<PlanetsView>(std::string("planets_view"), model.get());
      m_generalView     = std::make_shared<SelectorPanel>(std::string("general_view"));

      // Check whether we could create all the views.
      if (m_menuView == nullptr ||
          m_optionsView == nullptr ||
          m_resourcesView == nullptr ||
          m_planetsView == nullptr ||
          m_generalView == nullptr)
      {
        throw GuiException(std::string("Could not create one or more of the views needed for main display"));
      }

      // Add each one to the main layout.
      layout->addItem(m_optionsView,   0u, 0u, 12u, 1u);
      m_panel->addChild(m_optionsView);
      layout->addItem(m_menuView,      0u, 1u, 2u, 11u);
      m_panel->addChild(m_menuView);
      layout->addItem(m_resourcesView, 2u, 1u, 8u, 1u);
      m_panel->addChild(m_resourcesView);
      layout->addItem(m_planetsView,   10u, 1u, 2u, 11u);
      m_panel->addChild(m_planetsView);
      layout->addItem(m_generalView,   2u, 2u, 8u, 10u);
      m_panel->addChild(m_generalView);

      // Assign the layout to the main panel.
      m_panel->setLayout(layout);
    }

    void OgameView::createThematicViews(const unsigned& galaxyCount,
                                        const unsigned& systemCount,
                                        const unsigned& planetCount,
                                        player::GeneralDataModelShPtr model)
    {
      // Create the views.
      m_overView = std::make_shared<OverView>(getViewNameFromView(player::View::Overview), model);
      m_buildingsView = createGraphicContainer(getViewNameFromView(player::View::Resources));
      m_facilitiesView = createGraphicContainer(getViewNameFromView(player::View::Facilities));
      m_researchView = createGraphicContainer(getViewNameFromView(player::View::Research));
      m_shipyardView = createGraphicContainer(getViewNameFromView(player::View::Shipyard));
      m_defenseView = createGraphicContainer(getViewNameFromView(player::View::Defense));
      m_fleetView = createGraphicContainer(getViewNameFromView(player::View::Fleet));
      m_galaxyView = std::make_shared<GalaxyView>(getViewNameFromView(player::View::Galaxy), galaxyCount, systemCount, planetCount, model);
      m_allianceView = createGraphicContainer(getViewNameFromView(player::View::Alliance));

      // Add each one as a child of the general view for event propagation purposes.
      m_generalView->addChild(m_overView);
      m_generalView->addChild(m_buildingsView);
      m_generalView->addChild(m_facilitiesView);
      m_generalView->addChild(m_researchView);
      m_generalView->addChild(m_shipyardView);
      m_generalView->addChild(m_defenseView);
      m_generalView->addChild(m_fleetView);
      m_generalView->addChild(m_galaxyView);
      m_generalView->addChild(m_allianceView);

      m_generalView->setActiveChild(m_galaxyView->getName());
    }

    void OgameView::connectDataModel(player::GeneralDataModelShPtr dataModel) {
      // Connect each view to its dedicated slot in the data model.
      dataModel->registerForAction(player::Action::ChangeAccount, m_planetsView.get());
      dataModel->registerForAction(player::Action::ChangeAccount, m_optionsView.get());

      dataModel->registerForAction(player::Action::ChangePlanet, m_resourcesView.get());
      dataModel->registerForAction(player::Action::ChangePlanet, this);

      dataModel->registerForAction(player::Action::ChangeView, this);
    }

  }
}

