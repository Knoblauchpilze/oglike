
#include "ActionListener.h"
#include "DataModel.h"

namespace ogame {
  namespace player {

    ActionListener::ActionListener(const Action& action,
                                   DataModel* model):
      m_action(action),
      m_model(model)
    {
      // Nothing to do.
    }

    ActionListener::~ActionListener() {}

    void ActionListener::triggerAction() {
      if (m_model == nullptr) {
        throw DataModelException(std::string("Cannot trigger action, invalid null data model"));
      }
      m_model->triggerAction(m_action);
    }

  }
}
