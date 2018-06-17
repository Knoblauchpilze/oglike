#include "ArgumentsException.h"

namespace app {
  namespace arguments {

    ArgumentsException::ArgumentsException(const std::string& cause):
    std::exception(),
      m_cause(cause)
    {
      //ctor
    }

    ArgumentsException::~ArgumentsException()
    {
      //dtor
    }

    const char* ArgumentsException::what() const throw() {
      return m_cause.c_str();
    }

  }
}
