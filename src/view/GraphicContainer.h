#ifndef GRAPHIC_CONTAINER_H
#define GRAPHIC_CONTAINER_H

#include <memory>
#include <unordered_map>
#include "Drawable.h"
#include "Area.h"
#include "Layout.h"

namespace ogame {
  namespace view {

    class Layout;

    class GraphicContainer: public Drawable
    {
      public:

        virtual ~GraphicContainer();

        const std::string&
        getName() const noexcept;

        virtual void addChild(GraphicContainer* child);

        virtual void removeChild(GraphicContainer* child);

        utils::Area getRenderingArea() override;

        void setRenderingArea(const utils::Area& area) override;

        void setSize(const float& width, const float& height) override;

        void setLayout(Layout* layout);

      protected:

        GraphicContainer(const std::string& name, const utils::Area& area, Layout* layout = nullptr, GraphicContainer* parent = nullptr);

        void setParent(GraphicContainer* parent);

        const GraphicContainer* getParent() const noexcept;

        bool hasChanged() const noexcept override;

        virtual bool hasInternallyChanged() const noexcept;

        // We assume that the object is locked before entering this method.
        void makeDirty();

      private:

        bool childrenChanged() const noexcept;

      private:

        std::string m_name;
        utils::Area m_area;
        GraphicContainer* m_parent;
        Layout* m_layout;
        bool m_dirty;
        std::unordered_map<std::string, GraphicContainer*> m_children;

    };

    using GraphicContainerShPtr = std::shared_ptr<GraphicContainer>;
  }
}

#include "GraphicContainer.hxx"

#endif // GRAPHIC_CONTAINER_H
