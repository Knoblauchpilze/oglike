
#include "Layout.h"

namespace ogame {
  namespace view {

    Layout::Layout(GraphicContainer* container):
      m_container(nullptr),
      m_items()
    {
      setContainer(container);
    }

    Layout::~Layout() {
      if (m_container != nullptr) {
        m_container->setLayout(nullptr);
      }
    }

    void Layout::setContainer(GraphicContainer* container) {
      m_container = container;
    }

  }
}
