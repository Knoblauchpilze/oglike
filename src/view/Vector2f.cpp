
#include <cmath>
#include "Vector2f.h"
#include "ComparisonUtils.h"

namespace ogame {
  namespace view {
    namespace utils {

      Vector2f::Vector2f(const float& x, const float& y):
        m_x(x),
        m_y(y)
      {
        // Nothing to do
      }

      Vector2f::~Vector2f() {
        // Nothing to do
      }

      Vector2f::Vector2f(const Vector2f& other):
        m_x(other.m_x),
        m_y(other.m_y)
      {
        // Nothing to do
      }

      float Vector2f::normalize() {
        const float thisLength(length());
        if (!comparison::floatEqual(thisLength, 0.0f)) {
          m_x /= thisLength;
          m_y /= thisLength;
        }
        return thisLength;
      }

      Vector2f& Vector2f::normalized() {
        normalize();
        return (*this);
      }

      Vector2f& Vector2f::operator=(const Vector2f& other) {
        if (other == *this)
                {
          return *this;
        }
        m_x = other.m_x;
        m_y = other.m_y;
        return (*this);
      }

      float Vector2f::operator*(const Vector2f& other) const {
        return  m_x * other.m_x + m_y * other.m_y;
      }

      bool Vector2f::operator==(const Vector2f& other) const {
        return (comparison::floatEqual(m_x, other.m_x) &&
                comparison::floatEqual(m_y, other.m_y));
      }

      bool Vector2f::operator!=(const Vector2f& other) const {
        return !operator==(other);
      }

      Vector2f Vector2f::operator+(const Vector2f& other) const {
        Vector2f sum(*this);
        sum += other;
        return sum;
      }

      Vector2f& Vector2f::operator+=(const Vector2f& other) {
        m_x += other.m_x;
        m_y += other.m_y;
        return (*this);
      }

      Vector2f Vector2f::operator-(const Vector2f& other) const {
        Vector2f diff(*this);
        diff -= other;
        return diff;
      }

      Vector2f Vector2f::operator-() const {
          Vector2f minus;
          minus -= (*this);
          return minus;
      }

      Vector2f& Vector2f::operator-=(const Vector2f& other) {
        m_x -= other.m_x;
        m_y -= other.m_y;
        return (*this);
      }

      Vector2f Vector2f::operator*(const float& scale) const {
        Vector2f multiply(*this);
        multiply.m_x *= scale;
        multiply.m_y *= scale;
        return multiply;
      }

      Vector2f& Vector2f::operator*=(const float& scale) {
          m_x *= scale;
          m_y *= scale;
          return *this;
      }

      Vector2f Vector2f::operator/(const float& scale) const {
        Vector2f divide(*this);
        divide.m_x /= scale;
        divide.m_y /= scale;
        return divide;
      }

      Vector2f& Vector2f::operator/=(const float& scale) {
        m_x /= scale;
        m_y /= scale;
        return *this;
      }

      float Vector2f::operator^(const Vector2f& other) const {
          return m_x * other.m_y - m_y * other.m_x;
      }

      // Non-member functions
      Vector2f operator*(const float& scale, const Vector2f& vector) {
        return vector * scale;
      }

      std::ostream& operator<<(const Vector2f& vec, std::ostream& out) {
        out << vec.x() << "x" << vec.y();
        return out;
      }

      std::ostream& operator<<(std::ostream& out, const Vector2f& vec) {
        return operator<<(vec, out);
      }

    }
  }
}
