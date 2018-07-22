#ifndef RESEARCHVIEW_HXX
#define RESEARCHVIEW_HXX

#include "ResearchView.h"

namespace ogame {
  namespace gui {

    inline
    const std::string ResearchView::getDisplayForTech(const core::Research::Type& type, const core::Account& account) const noexcept {
      return std::to_string(account.getLevelForTechnology(type));
    }

  }
}

#endif // RESEARCHVIEW_HXX
