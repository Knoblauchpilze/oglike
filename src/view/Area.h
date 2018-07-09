#ifndef AREA_H
#define AREA_H

#include <SDL/SDL.h>
#include "Vector2f.h"

namespace ogame {
  namespace view {
    namespace utils {

      class Area
      {
        public:

          Area(const float& x = 0.0f, const float& y = 0.0f, const float& width = 0.0f, const float& height = 0.0f);

          inline float& x();

          inline const float& x() const;

          inline float& y();

          inline const float& y() const;

          inline float& w();

          inline const float& w() const;

          inline float& h();

          inline const float& h() const;

          inline float getLeftBound() const;

          inline float getRightBound() const;

          inline float getTopBound() const;

          inline float getBottomBound() const;

          inline Vector2f getCenter() const;

          inline Vector2f getTopLeftCorner() const;

          inline Vector2f getTopRightCorner() const;

          inline Vector2f getBottomRightCorner() const;

          inline Vector2f getBottomLeftCorner() const;

          inline float getSurface() const;

          bool contains(const Area& other) const;

          bool intersects(const Area& other) const;

          bool isInside(const Area& other) const;

          bool isInside(const Vector2f& point) const;

          // m_x and m_y are supposed to represent the top left corner of the area.
          bool isInsideRect(const Vector2f& point) const;

          Vector2f getNearestPoint(const Vector2f& point) const;

        private:

          float m_x;
          float m_y;
          float m_w;
          float m_h;
      };

    SDL_Rect createTopLeftBasedRectFromArea(const Area& area);

    SDL_Rect createCenteredBasedRectFromArea(const Area& area);

    }
  }
}

#include "Area.hxx"

#endif // AREA_H
