#ifndef ABSTRACTACTIONLISTENER_HXX
#define ABSTRACTACTIONLISTENER_HXX

#include "AbstractActionListener.h"

namespace ogame {
  namespace player {

    template <typename Action>
    AbstractActionListener<Action>::AbstractActionListener(AbstractDataModel<Action>* model):
      m_model(model)
    {
      // Nothing to do here.
    }

    template <typename Action>
    AbstractActionListener<Action>::~AbstractActionListener() {}

    template <typename Action>
    void AbstractActionListener<Action>::triggerAction(const Action& action) {
      m_model->triggerAction(action);
    }

  }
}

#endif // ABSTRACTACTIONLISTENER_HXX
