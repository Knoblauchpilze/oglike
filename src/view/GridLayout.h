#ifndef GRIDLAYOUT_H
#define GRIDLAYOUT_H

#include <memory>
#include "Layout.h"

namespace ogame {
  namespace view {

    class GridLayout: public Layout
    {
      public:

        GridLayout(const unsigned& width, const unsigned& height, GraphicContainer* container = nullptr);

        virtual ~GridLayout();

        void update() override;

        const unsigned& getWidth() const noexcept;

        const unsigned& getHeight() const noexcept;

      private:

        unsigned m_width;
        unsigned m_height;

    };

    using GridLayoutShPtr = std::shared_ptr<GridLayout>;
  }
}

#include "GridLayout.hxx"

#endif // GRIDLAYOUT_H
