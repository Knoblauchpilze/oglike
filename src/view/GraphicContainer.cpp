
#include "GraphicContainer.h"

namespace ogame {
  namespace view {

    GraphicContainer::GraphicContainer(const std::string& name, const utils::Area& area, Layout* layout, GraphicContainer* parent):
      Drawable(),
      m_name(name),
      m_area(area),
      m_parent(parent),
      m_layout(layout),
      m_dirty(true),
      m_children()
    {
        // Nothing to do
    }

    GraphicContainer::~GraphicContainer() {
        // Nothing to do
    }

    void GraphicContainer::setLayout(Layout* layout) {
      lock();
      m_layout = layout;
      if (m_layout != nullptr) {
        m_layout->setContainer(this);
        std::for_each(m_children.cbegin(), m_children.cend(),
          [this](const std::pair<std::string, GraphicContainer*>& child) {
            m_layout->addItem(child.second);
          }
        );
      }
      makeDirty();
      unlock();
    }

  }
}
