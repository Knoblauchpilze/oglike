#ifndef ABSTRACTDATAMODEL_HXX
#define ABSTRACTDATAMODEL_HXX

#include "AbstractDataModel.h"
#include "DataModelException.h"

namespace ogame {
  namespace player {

    template <typename Action>
    AbstractDataModel<Action>::AbstractDataModel(const std::string& name):
      m_name(name),
      m_listeners(),
      m_properties(),
      m_actions()
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

    template <typename Action>
    template <typename Property>
    void AbstractDataModel<Action>::addProperty(const std::string& name, const Action& action, Property* property) {
      // Add this property using the private handler.
      addPropertyWithNoAction(name, property);

      // Add the action for this property.
      m_actions[name] = action;

      // Trigger the corresponding action.
      triggerAction(action);
    }

    template <typename Action>
    template <typename Property>
    void AbstractDataModel<Action>::setProperty(const std::string& name, Property* property) {
      if (property == nullptr) {
        throw DataModelException(std::string("Cannot set property ") + name + ", invalid null property");
      }

      // Try to find the property in the internal table.
      typename Properties::iterator propertyIterator = m_properties.find(name);
      if (propertyIterator == m_properties.end()) {
        // Add this property.
        addPropertyWithNoAction(name, property);
      }
      else {
        m_properties[name] = property;
      }

      // Check whether this property should trigger an action.
      typename ActionByProperties::const_iterator actionIterator = m_actions.find(name);
      if (actionIterator != m_actions.cend()) {
        triggerAction(actionIterator->second);
      }
    }

    template <typename Action>
    template <typename Property>
    const Property* AbstractDataModel<Action>::getProperty(const std::string& name) const {
      // Try to find the property in the internal table.
      typename Properties::const_iterator propertyIterator = m_properties.find(name);
      if (propertyIterator == m_properties.cend()) {
        throw DataModelException(std::string("Cannot retrieve property ") + name + ", no such element registered in " + getName());
      }

      return reinterpret_cast<const Property*>(propertyIterator->second);
    }

    template <typename Action>
    template <typename Property>
    void AbstractDataModel<Action>::addPropertyWithNoAction(const std::string& name, Property* property) {
      if (property == nullptr) {
        throw DataModelException(std::string("Cannot add property ") + name + ", invalid null property");
      }

      // Try to find the property in the internal table.
      typename Properties::iterator propertyIterator = m_properties.find(name);
      if (propertyIterator != m_properties.end()) {
        throw DataModelException(std::string("Cannot add duplicated property ") + name + " in model " + getName());
      }

      m_properties[name] = reinterpret_cast<const void*>(property);
    }

  }
}

#endif // ABSTRACTDATAMODEL_HXX
