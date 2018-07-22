#ifndef FACILITIESVIEW_HXX
#define FACILITIESVIEW_HXX

#include "FacilitiesView.h"

namespace ogame {
  namespace gui {

    inline
    void FacilitiesView::populateActionData(const std::string& origin, ElementDescriptionPanel& action) const {
      std::cout << "[FACILITIES] Should create description for facility" <<  std::endl;
    }

    inline
    const std::string FacilitiesView::getDisplayForBuilding(const core::Building::Type& type, const core::Planet& planet) const noexcept {
      return std::to_string(0);
    }

  }
}

#endif // FACILITIESVIEW_HXX
