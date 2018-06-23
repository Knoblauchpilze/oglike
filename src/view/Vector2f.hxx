#ifndef VECTOR2F_HXX_INCLUDED
#define VECTOR2F_HXX_INCLUDED

#include <cmath>
#include "Vector2f.h"

namespace ogame {
  namespace view {
    namespace utils {

      inline float& Vector2f::x() {
        return m_x;
      }

      inline const float& Vector2f::x() const {
        return m_x;
      }

      inline void Vector2f::setX(const float& x) {
        m_x = x;
      }

      inline float& Vector2f::y() {
        return m_y;
      }

      inline const float& Vector2f::y() const {
        return m_y;
      }

      inline void Vector2f::setY(const float& y) {
        m_y = y;
      }

      inline float Vector2f::length() const {
        return std::sqrt(lengthSquared());
      }

      inline float Vector2f::lengthSquared() const {
        return m_x * m_x + m_y * m_y;
      }

    }
  }
}

#endif // VECTOR2F_HXX_INCLUDED
