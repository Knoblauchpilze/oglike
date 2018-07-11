#ifndef DATAMODEL_HXX
#define DATAMODEL_HXX

#include "DataModel.h"

namespace ogame {
  namespace player {

    inline
    void DataModel::registerForAction(const ActionListener::Action& action, ActionListenerShPtr listener) {
      if (listener != nullptr) {
        if (!listener->hasAction()) {
          listener->setAction(action);
        }
        m_listeners.push_back(listener);
      }
    }

  }
}

#endif // DATAMODEL_HXX
