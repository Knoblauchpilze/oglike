
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

    void Layout::update() {
      // Check if a container is assigned to this layout.
      if (m_container == nullptr) {
        return;
      }
      // And if some items are managed by this layout.
      if (m_items.empty()) {
        return;
      }

      // Retrieve available dimensions.
      utils::Area window = m_container->getRenderingArea();

      // Update with private handler.
      updatePrivate(window);
    }

    void Layout::setContainer(GraphicContainer* container) {
      m_container = container;
    }

  }
}
