#ifndef GRIDLAYOUT_H
#define GRIDLAYOUT_H

#include <memory>
#include <unordered_map>
#include "Layout.h"

namespace ogame {
  namespace view {

    class GridLayout: public Layout
    {
      public:

        GridLayout(const unsigned& width, const unsigned& height, const float& margin = 0.0f, GraphicContainer* container = nullptr);

        virtual ~GridLayout();

        const unsigned& getWidth() const noexcept;

        const unsigned& getHeight() const noexcept;

        const float& getMargin() const noexcept;

        int addItem(std::shared_ptr<GraphicContainer> container,
                    const unsigned& x,
                    const unsigned& y,
                    const unsigned& w,
                    const unsigned& h) override;

        void setGrid(const unsigned& w, const unsigned& h);

      protected:

        void updatePrivate(const utils::Area& area) override;

      private:

        // Convenience record to hold the position of items in the layout.
        struct ItemInfo {
          float x, y, w, h;
        };

        unsigned m_width;
        unsigned m_height;
        float m_margin;
        std::unordered_map<int, ItemInfo> m_itemsLocation;

    };

    using GridLayoutShPtr = std::shared_ptr<GridLayout>;
  }
}

#include "GridLayout.hxx"

#endif // GRIDLAYOUT_H
