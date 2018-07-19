
#include "Overview.h"

namespace ogame {
  namespace gui {

    OverView::OverView(const std::string& name, player::GeneralDataModelShPtr model):
      view::GraphicContainer(name,
                             view::utils::Area()),
      player::GeneralActionListener(model.get())
    {
      createView();

      connectDataModel(model);
    }

    OverView::~OverView() {}

    void OverView::createView() {}

    void OverView::connectDataModel(player::GeneralDataModelShPtr dataModel) {
      dataModel->registerForAction(player::Action::ChangePlanet, this);
    }

    void OverView::populateWithPlanetData(const core::Planet& planet) {
      
    }
  }
}
