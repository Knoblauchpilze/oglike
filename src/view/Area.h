#ifndef AREA_H
#define AREA_H

#include <iostream>
#include <SDL/SDL.h>
#include "Vector2d.h"

namespace ogame {
  namespace view {
    namespace utils {

      class Area
      {
        public:

          Area(const double& x = 0.0, const double& y = 0.0, const double& width = 0.0, const double& height = 0.0);

          inline double& getX();

          inline const double& getX() const;

          inline double& getY();

          inline const double& getY() const;

          inline double& getWidth();

          inline const double& getWidth() const;

          inline double& getHeight();

          inline const double& getHeight() const;

          inline double getLeftBound() const;

          inline double getRightBound() const;

          inline double getTopBound() const;

          inline double getBottomBound() const;

          inline Vector2d getCenter() const;

          inline Vector2d getTopLeftCorner() const;

          inline Vector2d getTopRightCorner() const;

          inline Vector2d getBottomRightCorner() const;

          inline Vector2d getBottomLeftCorner() const;

          inline void setX(const double& x);

          inline void setY(const double& y);

          inline void setWidth(const double& width);

          inline void setHeight(const double& height);

          inline double getSurface() const;

          bool contains(const Area& other) const;

          bool intersects(const Area& other) const;

          bool isInside(const Area& other) const;

          bool isInside(const Vector2d& point) const;

          Vector2d getNearestPoint(const Vector2d& point) const;

        private:

          double m_x;
          double m_y;
          double m_w;
          double m_h;
      };

    SDL_Rect createTopLeftBasedRectFromArea(const Area& area);

    SDL_Rect createCenteredBasedRectFromArea(const Area& area);

    }
  }
}

#include "Area.hxx"

#endif // AREA_H
