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
    void ValueSelector::onActionTriggered(const player::GeneralDataModel& model) {}

  }
}

#endif // VALUESELECTOR_HXX
