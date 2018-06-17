
#include "Area.h"

namespace ogame {
  namespace view {
    namespace utils {

      Area::Area(const double& x, const double& y, const double& width, const double& height) :
        m_x(x),
        m_y(y),
        m_w(width),
        m_h(height)
      {
        // Nothing to do
      }

      bool Area::contains(const Area& other) const {
        if (other.getLeftBound() < getLeftBound()) {
            return false;
        }
        if (other.getRightBound() > getRightBound()) {
            return false;
        }
        if (other.getTopBound() > getTopBound()) {
            return false;
        }
        if (other.getBottomBound() < getBottomBound()) {
            return false;
        }
        return true;
      }

      bool Area::intersects(const Area& other) const {
        if (other.getRightBound() < getLeftBound()) {
            return false;
        }
        if (other.getLeftBound() > getRightBound()) {
            return false;
        }
        if (other.getTopBound() < getBottomBound()) {
            return false;
        }
        if (other.getBottomBound() > getTopBound()) {
            return false;
        }
        return true;
      }

      bool Area::isInside(const Area& other) const {
        if (other.getLeftBound() >= getLeftBound() &&
            other.getRightBound() <= getRightBound() &&
            other.getTopBound() <= getTopBound() &&
            other.getBottomBound() >= getBottomBound())
        {
          return true;
        }
        return false;
      }

      bool Area::isInside(const Vector2d& point) const {
        if (getLeftBound() > point.x() || getRightBound() < point.x()) {
          return false;
        }
        if (getBottomBound() > point.y() || getTopBound() < point.y())  {
          return false;
        }
        return true;
      }

      Vector2d Area::getNearestPoint(const Vector2d& point) const {
        const double nearestX(getLeftBound() > point.x() ? getLeftBound() : (getRightBound() < point.x() ? getRightBound() : point.x()));
        const double nearestY(getBottomBound() > point.y() ? getBottomBound() : (getTopBound() < point.y() ? getTopBound() : point.y()));
        return Vector2d(nearestX, nearestY);
      }

  //=====================

      SDL_Rect createTopLeftBasedRectFromArea(const Area& area) {
        SDL_Rect outputRect = { static_cast<short int>(area.getX()), static_cast<short int>(area.getY()), static_cast<short unsigned int>(area.getWidth()), static_cast<short unsigned int>(area.getHeight()) };
        return outputRect;
      }

      SDL_Rect createCenteredBasedRectFromArea(const Area& area) {
        SDL_Rect outputRect = { static_cast<short int>(area.getLeftBound()), static_cast<short int>(area.getTopBound()), static_cast<short unsigned int>(area.getWidth()), static_cast<short unsigned int>(area.getHeight()) };
        return outputRect;
      }

    }
  }
}
