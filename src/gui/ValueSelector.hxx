#ifndef VALUESELECTOR_HXX
#define VALUESELECTOR_HXX

#include "ValueSelector.h"

namespace ogame {
  namespace gui {

    inline
    const unsigned ValueSelector::getActiveOption() {
      lock();
      const unsigned option = m_selectedOption;
      unlock();
      return option;
    }

    inline
    void ValueSelector::onMouseButtonReleasedEventPrivate(const SDL_MouseButtonEvent& mouseButtonEvent) {
      // Avoid sending twice this signal as it is already handled by the onInteractionPerformed method.
    }

  }
}

#endif // VALUESELECTOR_HXX
