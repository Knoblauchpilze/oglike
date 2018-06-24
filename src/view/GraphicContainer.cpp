
#include "GraphicContainer.h"

namespace ogame {
  namespace view {

    GraphicContainer::GraphicContainer(const std::string& name,
                                       const utils::Area& area,
                                       const EventListener::Interaction::Mask& mask,
                                       Layout* layout,
                                       GraphicContainer* parent):
      Drawable(),
      EventListener(mask),
      m_name(name),
      m_area(area),
      m_parent(parent),
      m_layout(layout),
      m_dirty(true),
      m_deepDirty(true),
      m_children(),
      m_panel(nullptr),
      m_color()
    {
      m_color = {
        static_cast<unsigned char>(std::rand() % 255),
        static_cast<unsigned char>(std::rand() % 255),
        static_cast<unsigned char>(std::rand() % 255)
      };
      createContent();
      if (m_layout != nullptr) {
        m_layout->setContainer(this);
      }
    }

    GraphicContainer::~GraphicContainer() {
      destroyContent();
    }

    void GraphicContainer::addChild(GraphicContainer* child) {
      if (child != nullptr) {
        m_children[child->getName()] = child;
        if (m_layout != nullptr) {
          m_layout->addItem(child);
        }
      }
    }

    void GraphicContainer::removeChild(GraphicContainer* child) {
      if (child != nullptr) {
        m_children.erase(child->getName());
        if (m_layout != nullptr) {
          m_layout->removeItem(child);
        }
      }
    }

    SDL_Surface* GraphicContainer::draw() {
      SDL_Surface* rendering = nullptr;
      lock();
      if (hasChanged()) {
        // Render this container.
        if (m_deepDirty) {
          createContent();
        }
        else {
          clearContent();
        }

        // Update layout if any.
        if (m_layout != nullptr) {
          unlock();
          m_layout->update();
          lock();
        }

        // Proceed to update of children containers if any.
        for (std::unordered_map<std::string, GraphicContainer*>::const_iterator child = m_children.cbegin() ;
             child != m_children.cend() ;
             ++child)
        {
          try {
            drawChild(child->second);
          }
          catch (const GraphicContainerException& e) {
            std::cerr << "[CONTAINER] Caught internal exception while repainting child " << child->first << " for container " << getName() << std::endl << e.what() << std::endl;
          }
        }

        // Container updated.
        m_dirty = false;
        m_deepDirty = false;
      }

      // Use either cached value or newly produced one.
      rendering = m_panel;
      unlock();

      return rendering;
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

    void GraphicContainer::setBackgroundColor(const SDL_Color& color) {
      lock();
      m_color = color;
      makeDirty();
      unlock();
    }

  }
}
