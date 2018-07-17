
#include "DataModel.h"

#include <iostream>

namespace ogame {
  namespace player {

    DataModel::DataModel(const std::string& name,
                         const View& initView):
      m_name(name),
      m_listeners(),
      m_activeAccount(nullptr),
      m_activePlanet(nullptr),
      m_activeView(initView)
    {
      // Nothing to do here.
    }

    DataModel::~DataModel() {}

    void DataModel::registerForAction(const Action& action, ActionListener* listener) {
      if (listener != nullptr) {
        // Create or add this action and this listener.
        ListenersByAction::iterator listenersForAction = m_listeners.find(action);
        if (listenersForAction == m_listeners.end()) {
          // Create this action.
          m_listeners[action] = std::vector<ActionListener*>(1, listener);
        }
        else {
          listenersForAction->second.push_back(listener);
        }
      }
    }

    void DataModel::triggerAction(const Action& action) {
      // Try to retrieve the listeners for this action.
      ListenersByAction::const_iterator listenersForAction = m_listeners.find(action);
      if (listenersForAction != m_listeners.cend()) {
        for (unsigned listenerIndex = 0u ; listenerIndex < listenersForAction->second.size() ; ++listenerIndex) {
          ActionListener* listener = listenersForAction->second[listenerIndex];
          if (listener != nullptr) {
            listener->onActionTriggered(*this);
          }
        }
      }
    }

    void DataModel::setActiveAccount(core::Account* account) {
      if (m_activeAccount != account) {
        m_activeAccount = account;

        // Assign the active planet to be the homeworld of this account.
        if (m_activeAccount != nullptr) {
          setActivePlanet(&m_activeAccount->getHomeWorld());
        }

        // Finally trigger the change account action.
        triggerAction(Action::ChangeAccount);
      }
    }

    void DataModel::setActivePlanet(core::Planet* planet) {
      if (m_activePlanet != planet) {
        m_activePlanet = planet;
        triggerAction(Action::ChangePlanet);
      }
    }

    void DataModel::setActiveView(const View& view) {
      if (m_activeView != view) {
        m_activeView = view;
        triggerAction(Action::ChangeView);
      }
    }

  }
}
