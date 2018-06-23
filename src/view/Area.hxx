#ifndef AREA_HXX_INCLUDED
#define AREA_HXX_INCLUDED

#include "Area.h"

namespace ogame {
  namespace view {
    namespace utils {

      inline float& Area::x() {
        return m_x;
      }

      inline const float& Area::x() const {
        return m_x;
      }

      inline float& Area::y() {
        return m_y;
      }

      inline const float& Area::y() const {
        return m_y;
      }

      inline float Area::getLeftBound() const {
        return m_x - m_w / 2.0f;
      }

      inline float Area::getRightBound() const {
        return m_x + m_w / 2.0f;
      }

      inline float Area::getTopBound() const {
        return m_y + m_h / 2.0f;
      }

      inline float Area::getBottomBound() const {
        return m_y - m_h / 2.0f;
      }

      inline utils::Vector2f Area::getCenter() const {
          return utils::Vector2f(m_x, m_y);
      }

      inline utils::Vector2f Area::getTopLeftCorner() const {
          return utils::Vector2f(m_x - m_w / 2.0f, m_y + m_h / 2.0f);
      }

      inline utils::Vector2f Area::getTopRightCorner() const {
          return utils::Vector2f(m_x + m_w / 2.0f, m_y + m_h / 2.0f);
      }

      inline utils::Vector2f Area::getBottomRightCorner() const {
          return utils::Vector2f(m_x + m_w / 2.0f, m_y - m_h / 2.0f);
      }

      inline utils::Vector2f Area::getBottomLeftCorner() const {
          return utils::Vector2f(m_x - m_w / 2.0f, m_y - m_h / 2.0f);
      }

      inline float& Area::w() {
        return m_w;
      }

      inline const float& Area::w() const {
        return m_w;
      }

      inline float& Area::h() {
        return m_h;
      }

      inline const float& Area::h() const {
        return m_h;
      }

      inline float Area::getSurface() const {
        return m_w * m_h;
      }

    }
  }
}

#endif // AREA_HXX_INCLUDED
