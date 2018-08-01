#ifndef COMPARISONUTILS_H
#define COMPARISONUTILS_H

#include "Vector2f.h"

namespace ogame {
  namespace view {
    namespace comparison {

      bool floatEqual(const float& value1, const float& value2);

      bool nullVector(const utils::Vector2f& vector);

    }
  }
}

#endif // COMPARISONUTILS_H
