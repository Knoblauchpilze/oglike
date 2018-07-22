#ifndef BUILDINGSVIEW_HXX
#define BUILDINGSVIEW_HXX

#include "BuildingsView.h"

namespace ogame {
  namespace gui {

    inline
    void BuildingsView::populateActionData(const std::string& origin, ElementDescriptionPanel& action) const {
      std::cout << "[BUILDINGS] Should create description for building" <<  std::endl;
    }

    inline
    const std::string BuildingsView::getDisplayForBuilding(const core::Building::Type& type, const core::Planet& planet) const noexcept {
      return std::to_string(0);
    }

  }
}

#endif // BUILDINGSVIEW_HXX
