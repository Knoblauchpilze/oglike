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

        SDL_Surface* draw() override;

        void setLayout(Layout* layout);

        void setBackgroundColor(const SDL_Color& color);

        GraphicContainer(const std::string& name, const utils::Area& area, Layout* layout = nullptr, GraphicContainer* parent = nullptr);

      protected:

        void setParent(GraphicContainer* parent);

        const GraphicContainer* getParent() const noexcept;

        bool hasChanged() const noexcept override;

        virtual bool hasInternallyChanged() const noexcept;

      private:

        // We assume that the object is locked before entering this method.
        void makeDirty();

        // We assume that the object is locked before entering this method.
        void makeDeepDirty();

        bool childrenChanged() const noexcept;

        void createContent();

        void clearContent();

        void destroyContent();

        void drawChild(GraphicContainer* child);

      private:

        std::string m_name;
        utils::Area m_area;
        GraphicContainer* m_parent;
        Layout* m_layout;
        bool m_dirty;
        bool m_deepDirty;
        std::unordered_map<std::string, GraphicContainer*> m_children;
        SDL_Surface* m_panel;
        SDL_Color m_color;

    };

    using GraphicContainerShPtr = std::shared_ptr<GraphicContainer>;
  }
}

#include "GraphicContainer.hxx"

#endif // GRAPHIC_CONTAINER_H