
#include "GraphicContainer.h"

namespace ogame {
  namespace view {

    GraphicContainer::GraphicContainer(const std::string& name,
                                       const utils::Area& area,
                                       const EventListener::Interaction::Mask& mask,
                                       const bool transparent,
                                       const EventListener::Sensitivity& sensitivity,
                                       LayoutShPtr layout,
                                       GraphicContainer* parent):
      Drawable(),
      EventListener(mask, sensitivity),
      m_name(name),
      m_area(area),
      m_parent(parent),
      m_layout(layout),
      m_dirty(true),
      m_deepDirty(true),
      m_children(),
      m_listeners(),
      m_panel(nullptr),
      m_transparent(transparent),
      m_enabled(true),
      m_color()
    {
      m_color = {
        static_cast<unsigned char>(std::rand() % 255),
        static_cast<unsigned char>(std::rand() % 255),
        static_cast<unsigned char>(std::rand() % 255)
      };
      try {
        createContent();
      }
      catch (const ViewException& e) {
        std::cerr << "[GRAPHIC] Caught internal exception while rendering container " << getName() << ":" << std::endl << e.what() << std::endl;
      }
      if (m_layout != nullptr) {
        m_layout->setContainer(this);
      }
    }

    GraphicContainer::~GraphicContainer() {
      destroyContent();
    }

    void GraphicContainer::addChild(GraphicContainerShPtr child) {
      if (child != nullptr) {
        m_children[child->getName()] = child;
        child->setParent(this);
        if (m_layout != nullptr) {
          m_layout->addItem(child);
        }
      }
    }

    void GraphicContainer::addChild(std::shared_ptr<GraphicContainer> child,
                                    const unsigned& x,
                                    const unsigned& y,
                                    const unsigned& w,
                                    const unsigned& h)
    {
      if (child != nullptr) {
        m_children[child->getName()] = child;
        child->setParent(this);
        if (m_layout != nullptr) {
          m_layout->addItem(child, x, y, w, h);
        }
      }
    }

    void GraphicContainer::removeChild(GraphicContainerShPtr child) {
      if (child != nullptr) {
        m_children.erase(child->getName());
        if (m_layout != nullptr) {
          m_layout->removeItem(child);
        }
      }
    }

    void GraphicContainer::removeChild(const std::string& name) {
      const std::unordered_map<std::string, GraphicContainerShPtr>::const_iterator child = m_children.find(name);
      if (child != m_children.cend()) {
        removeChild(child->second);
      }
    }

    SDL_Surface* GraphicContainer::draw() {
      SDL_Surface* rendering = nullptr;
      lock();
      if (hasChanged()) {
        // Render this container.
        if (m_deepDirty) {

          try {
            createContent();
          }
          catch (const GraphicContainerException& e) {
            std::cerr << "[GRAPHIC] Caught internal exception while rendering container " << getName() << ":" << std::endl << e.what() << std::endl;
            // Release the locker on this object.
            unlock();

            // Propagate the exception.
            throw;
          }
          catch (const ViewException& e) {
            std::cerr << "[GRAPHIC] Caught view exception while rendering container " << getName() << ":" << std::endl << e.what() << std::endl;
            // Release the locker on this object.
            unlock();

            // Propagate the exception.
            throw;
          }
        }
        else {
          clearContentPrivate(m_panel);
        }

        // Update layout if any.
        if (m_layout != nullptr) {
          unlock();
          m_layout->update();
          lock();
        }

        // Proceed to update of children containers if any.
        for (std::unordered_map<std::string, GraphicContainerShPtr>::const_iterator child = m_children.cbegin() ;
             child != m_children.cend() ;
             ++child)
        {
          try {
            drawChild(child->second);
          }
          catch (const GraphicContainerException& e) {
            std::cerr << "[CONTAINER] Caught internal exception while repainting child " << child->first << " for container " << getName() << std::endl << e.what() << std::endl;
          }
          catch (const ViewException& e) {
            std::cerr << "[CONTAINER] Caught view exception while repainting child container " << child->first << " for container " << getName() << std::endl << e.what() << std::endl;
          }
        }

        if (!m_enabled) {
          try {
            disableContentPrivate(m_panel);
          }
          catch (const GraphicContainerException& e) {
            std::cerr << "[GRAPHIC] Caught internal exception while disabling container " << getName() << ":" << std::endl << e.what() << std::endl;
            // Release the locker on this object.
            unlock();

            // Propagate the exception.
            throw;
          }
          catch (const ViewException& e) {
            std::cerr << "[GRAPHIC] Caught view exception while disabling container " << getName() << ":" << std::endl << e.what() << std::endl;
            // Release the locker on this object.
            unlock();

            // Propagate the exception.
            throw;
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

    void GraphicContainer::setLayout(LayoutShPtr layout) {
      lock();
      m_layout = layout;
      if (m_layout != nullptr) {
        m_layout->setContainer(this);
        std::for_each(m_children.cbegin(), m_children.cend(),
          [this](const std::pair<std::string, GraphicContainerShPtr>& child) {
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
