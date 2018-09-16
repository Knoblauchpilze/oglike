
#include "AbstractDataModel.h"

namespace ogame {
  namespace player {

    AbstractDataModel::AbstractDataModel(const std::string& name):
      m_name(name),
      m_listeners(),
      m_activeView(View::Overview),
      m_activePlanet(nullptr),
      m_activeAccount(nullptr),
      m_activeSystemCoordinate(0u),
      m_activeGalaxyCoordinate(0u),
      m_research(core::Research::Type::Energy),
      m_building(core::Building::Type::MetalMine),
      m_ship(core::Ship::Type::LightFighter),
      m_defense(core::Defense::Type::MissileLauncher),
      m_unitCount(1u)
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
            listener->onActionTriggered(*this, action);
          }
        }
      }
    }

  }
}
