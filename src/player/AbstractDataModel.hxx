#ifndef ABSTRACTDATAMODEL_HXX
#define ABSTRACTDATAMODEL_HXX

#include "AbstractDataModel.h"

namespace ogame {
  namespace player {

    template <typename Action>
    AbstractDataModel<Action>::AbstractDataModel(const std::string& name):
      m_name(name),
      m_listeners()
    {
      // Nothing to do.
    }

    template <typename Action>
    AbstractDataModel<Action>::~AbstractDataModel() {}

    template <typename Action>
    const std::string& AbstractDataModel<Action>::getName() const noexcept {
      return m_name;
    }

    template <typename Action>
    void AbstractDataModel<Action>::registerForAction(const Action& action, AbstractActionListener<Action>* listener) {
      if (listener != nullptr) {
        // Create or add this action and this listener.
        typename ListenersByAction::iterator listenersForAction = m_listeners.find(action);
        if (listenersForAction == m_listeners.end()) {
          // Create this action.
          m_listeners[action] = std::vector<AbstractActionListener<Action>*>(1, listener);
        }
        else {
          listenersForAction->second.push_back(listener);
        }
      }
    }

    template <typename Action>
    void AbstractDataModel<Action>::triggerAction(const Action& action) {
      // Try to retrieve the listeners for this action.
      typename ListenersByAction::const_iterator listenersForAction = m_listeners.find(action);
      if (listenersForAction != m_listeners.cend()) {
        for (unsigned listenerIndex = 0u ; listenerIndex < listenersForAction->second.size() ; ++listenerIndex) {
          AbstractActionListener<Action>* listener = listenersForAction->second[listenerIndex];
          if (listener != nullptr) {
            listener->onActionTriggered(*this);
          }
        }
      }
    }

  }
}

#endif // ABSTRACTDATAMODEL_HXX
