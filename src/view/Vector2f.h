#ifndef VECTOR2F_H
#define VECTOR2F_H

#include <iostream>

namespace ogame {
  namespace view {
    namespace utils {

      class Vector2f
      {
        public:

          explicit Vector2f(const float& x = 0.0f, const float& y = 0.0f);

          ~Vector2f();

          Vector2f(const Vector2f& other);

          Vector2f& operator=(const Vector2f& other);

          inline float& x();

          inline const float& x() const;

          inline void setX(const float& x);

          inline float& y();

          inline const float& y() const;

          inline void setY(const float& y);

          inline float length() const;

          inline float lengthSquared() const;

          float normalize();

          Vector2f& normalized();

          float operator*(const Vector2f& other) const;

          bool operator==(const Vector2f& other) const;

          bool operator!=(const Vector2f& other) const;

          Vector2f operator+(const Vector2f& other) const;

          Vector2f& operator+=(const Vector2f& other);

          Vector2f operator-(const Vector2f& other) const;

          Vector2f operator-() const;

          Vector2f& operator-=(const Vector2f& other);

          Vector2f operator*(const float& scale) const;

          Vector2f& operator*=(const float& scale);

          Vector2f operator/(const float& scale) const;

          Vector2f& operator/=(const float& scale);

          float operator^(const Vector2f& other) const;

        private:

          float m_x;
          float m_y;
      };

      Vector2f operator*(const float& scale, const Vector2f& vector);

      std::ostream& operator<<(const Vector2f& vec, std::ostream& out);

      std::ostream& operator<<(std::ostream& out, const Vector2f& vec);

    }
  }
}

#include "Vector2f.hxx"

#endif // VECTOR2F_H
