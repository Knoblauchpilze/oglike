#ifndef BUILDINGSVIEW_HXX
#define BUILDINGSVIEW_HXX

#include "BuildingsView.h"

namespace ogame {
  namespace gui {

    inline
    const std::string BuildingsView::getDisplayForBuilding(const core::Building::Type& type, const core::Planet& planet) const noexcept {
      return std::to_string(0);
    }

  }
}

#endif // BUILDINGSVIEW_HXX
