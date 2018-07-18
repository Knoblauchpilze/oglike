#ifndef ABSTRACTACTIONLISTENER_HXX
#define ABSTRACTACTIONLISTENER_HXX

#include "AbstractActionListener.h"
#include "DataModelException.h"

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
    template <typename Property>
    void AbstractActionListener<Action>::setProperty(const std::string& name, Property* property) {
      if (property == nullptr) {
        throw DataModelException(std::string("Cannot set property ") + name + ", invalid null property");
      }
      m_model->setProperty(name, property);
    }

    template <typename Action>
    void AbstractActionListener<Action>::triggerAction(const Action& action) {
      if (m_model == nullptr) {
        throw DataModelException(std::string("Cannot trigger action, invalid null data model"));
      }
      m_model->triggerAction(action);
    }

  }
}

#endif // ABSTRACTACTIONLISTENER_HXX
