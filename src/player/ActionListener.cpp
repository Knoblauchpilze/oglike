
#include "ActionListener.h"
#include "DataModel.h"

#include <iostream>

namespace ogame {
  namespace player {

    ActionListener::ActionListener(DataModel* model):
      m_model(model)
    {
      // Nothing to do.
    }

    ActionListener::~ActionListener() {}

    void ActionListener::setActiveView(const View& view) {
      m_model->setActiveView(view);
    }

    void ActionListener::triggerAction(const Action& action) {
      if (m_model == nullptr) {
        throw DataModelException(std::string("Cannot trigger action, invalid null data model"));
      }
      m_model->triggerAction(action);
    }

  }
}
