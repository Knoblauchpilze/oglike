#ifndef LINEARLAYOUT_H
#define LINEARLAYOUT_H

#include <memory>
#include "Layout.h"

namespace ogame {
  namespace view {

    class LinearLayout: public Layout
    {
      public:

        enum class Direction {
          Horizontal,
          Vertical
        };

        LinearLayout(const Direction& direction, GraphicContainer* container = nullptr);

        virtual ~LinearLayout();

        void update() override;

        const Direction& getDirection() const noexcept;

      private:

        Direction m_direction;

    };

    using LinearLayoutShPtr = std::shared_ptr<LinearLayout>;
  }
}

#include "LinearLayout.hxx"

#endif // LINEARLAYOUT_H
