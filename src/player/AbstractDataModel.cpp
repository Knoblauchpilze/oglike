
#include "AbstractDataModel.h"
#include "DataModelException.h"

namespace ogame {
  namespace player {

    AbstractDataModel::AbstractDataModel(const std::string& name):
      m_name(name),
      m_listeners(),
      m_activeView(View::Overview),
      m_activePlanet(nullptr),
      m_activeAccount(nullptr),
      m_activeSystemCoordinate(0u),
      m_activeGalaxyCoordinate(0u)
    {
      // Nothing to do.
    }

    AbstractDataModel::~AbstractDataModel() {}

    const std::string& AbstractDataModel::getName() const noexcept {
      return m_name;
    }

    void AbstractDataModel::registerForAction(const Action& action, AbstractActionListener* listener) {
      if (listener != nullptr) {
        // Create or add this action and this listener.
        ListenersByAction::iterator listenersForAction = m_listeners.find(action);
        if (listenersForAction == m_listeners.end()) {
          // Create this action.
          m_listeners[action] = std::vector<AbstractActionListener*>(1, listener);
        }
        else {
          listenersForAction->second.push_back(listener);
        }
      }
    }

    void AbstractDataModel::triggerAction(const Action& action) {
      // Try to retrieve the listeners for this action.
      ListenersByAction::const_iterator listenersForAction = m_listeners.find(action);
      if (listenersForAction != m_listeners.cend()) {
        for (unsigned listenerIndex = 0u ; listenerIndex < listenersForAction->second.size() ; ++listenerIndex) {
          AbstractActionListener* listener = listenersForAction->second[listenerIndex];
          if (listener != nullptr) {
            listener->onActionTriggered(*this);
          }
        }
      }
    }

    void AbstractDataModel::setActiveView(const View& view) {
      m_activeView = view;
      triggerAction(Action::ChangeView);
    }

    void AbstractDataModel::setActivePlanet(core::Planet* planet) {
      if (planet == nullptr) {
        throw DataModelException(std::string("Cannot set active planet for model ") + getName() + ", invalid null pointer");
      }
      m_activePlanet = planet;
      triggerAction(Action::ChangePlanet);
    }

    void AbstractDataModel::setActiveAccount(core::Account* account) {
      if (account == nullptr) {
        throw DataModelException(std::string("Cannot set active account for model ") + getName() + ", invalid null pointer");
      }
      m_activeAccount = account;
      triggerAction(Action::ChangeAccount);
    }

    void AbstractDataModel::setActiveSystemCoordinate(const unsigned& coordinate) {
      m_activeSystemCoordinate = coordinate;
      triggerAction(Action::ChangeSystem);
    }

    void AbstractDataModel::setActiveGalaxyCoordinate(const unsigned& coordinate) {
      m_activeGalaxyCoordinate = coordinate;
      triggerAction(Action::ChangeGalaxy);
    }

    const View& AbstractDataModel::getActiveView() const {
      return m_activeView;
    }

    const core::Planet& AbstractDataModel::getActivePlanet() const {
      if (m_activePlanet == nullptr) {
        throw DataModelException(std::string("Cannot retrieve active planet for model ") + getName() + ", invalid null pointer");
      }
      return *m_activePlanet;
    }

    const core::Account& AbstractDataModel::getActiveAccount() const {
      if (m_activeAccount == nullptr) {
        throw DataModelException(std::string("Cannot retrieve active account for model ") + getName() + ", invalid null pointer");
      }
      return *m_activeAccount;
    }

    const unsigned& AbstractDataModel::getActiveSystemCoordinate() const {
      return m_activeSystemCoordinate;
    }

    const unsigned& AbstractDataModel::getActiveGalaxyCoordinate() const {
      return m_activeGalaxyCoordinate;
    }

  }
}
