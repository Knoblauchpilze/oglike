#ifndef LAYOUT_H
#define LAYOUT_H

#include <memory>
#include <vector>
#include "Area.h"
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

        void update();

        void setContainer(GraphicContainer* container);

        virtual int addItem(std::shared_ptr<GraphicContainer> item);

        virtual int addItem(std::shared_ptr<GraphicContainer> item,
                            const unsigned& x,
                            const unsigned& y,
                            const unsigned& w,
                            const unsigned& h);

        virtual void removeItem(std::shared_ptr<GraphicContainer> item);

      protected:

        virtual void updatePrivate(const utils::Area& window) = 0;

      private:

        std::shared_ptr<GraphicContainer> getContainerOrNull(std::shared_ptr<GraphicContainer> item, int* index = nullptr) const;

      protected:

        GraphicContainer* m_container;
        std::vector<std::shared_ptr<GraphicContainer>> m_items;

    };

    using LayoutShPtr = std::shared_ptr<Layout>;
  }
}

#include "Layout.hxx"

#endif // LAYOUT_H
