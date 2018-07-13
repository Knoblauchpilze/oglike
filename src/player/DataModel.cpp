
#include "DataModel.h"

namespace ogame {
  namespace player {

    DataModel::DataModel(const View& initView):
      m_listeners(),
      m_activeAccount(nullptr),
      m_activePlanet(nullptr),
      m_activeView(initView)
    {
      // Nothing to do here.
    }

    DataModel::~DataModel() {}

    void DataModel::triggerAction(const ActionListener::Action& action) {
      for (unsigned listenerIndex = 0u ; listenerIndex < m_listeners.size() ; ++listenerIndex) {
        ActionListener* listener = m_listeners[listenerIndex];
        if (listener != nullptr && listener->getAction() == action) {
          listener->onActionTriggered(*this);
        }
      }
    }

  }
}
