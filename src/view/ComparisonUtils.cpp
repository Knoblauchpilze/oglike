
#include <limits>
#include <cmath>
#include "ComparisonUtils.h"

namespace ogame {
  namespace view {
    namespace comparison {

      bool doubleEqual(const double& value1, const double& value2) {
        double epsilon(5.0f * std::numeric_limits<double>::epsilon());
        return (std::abs(value1 - value2) < epsilon);
      }

      bool floatEqual(const float& value1, const float& value2) {
        float epsilon(5.0f * std::numeric_limits<float>::epsilon());
        return (std::fabs(value1 - value2) < epsilon);
      }

      bool nullVector(const utils::Vector2f& vector) {
        return (doubleEqual(vector.x(), 0.0f) && doubleEqual(vector.y(), 0.0f));
      }

    }
  }
}
