#ifndef LAYOUT_H
#define LAYOUT_H

#include <memory>
#include <vector>
#include "GraphicContainer.h"

namespace ogame {
  namespace view {

    class GraphicContainer;

    // Slave class of GraphicContainer.
    class Layout
    {
      public:

        Layout(GraphicContainer* container = nullptr);

        virtual ~Layout();

        virtual void update() = 0;

        void setContainer(GraphicContainer* container);

        void addItem(GraphicContainer* item);

        void removeItem(GraphicContainer* item);

      private:

        GraphicContainer* getContainerOrNull(GraphicContainer* item, int* index = nullptr) const;

      protected:

        GraphicContainer* m_container;
        std::vector<GraphicContainer*> m_items;

    };

    using LayoutShPtr = std::shared_ptr<Layout>;
  }
}

#include "Layout.hxx"

#endif // LAYOUT_H
