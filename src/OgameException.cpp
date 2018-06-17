
#include "OgameException.h"

namespace ogame {
  namespace core {

    OgameException::OgameException(const std::string& cause):
      std::exception(),
      m_cause(cause)
    {
      //ctor
    }

    OgameException::~OgameException()
    {
      //dtor
    }

    const char* OgameException::what() const throw() {
      return m_cause.c_str();
    }

  }
}
