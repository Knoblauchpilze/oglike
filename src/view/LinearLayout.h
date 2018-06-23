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

        LinearLayout(const Direction& direction, const float& margin = 1.0f, const float& interMargin = 0.0f, GraphicContainer* container = nullptr);

        virtual ~LinearLayout();

        const Direction& getDirection() const noexcept;

        const float& getMargin() const noexcept;

        const float& getComponentMargin() const noexcept;

      protected:

        void updatePrivate(const utils::Area& window) override;

      private:

        void handleHorizontalLayout(const utils::Area& totalArea, float& cw, float& ch) const;

        void handleVerticalLayout(const utils::Area& totalArea, float& cw, float& ch) const;

      private:

        Direction m_direction;
        float m_margin;
        float m_componentMargin;

    };

    using LinearLayoutShPtr = std::shared_ptr<LinearLayout>;
  }
}

#include "LinearLayout.hxx"

#endif // LINEARLAYOUT_H
