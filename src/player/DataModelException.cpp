
#include "DataModelException.h"

namespace ogame {
  namespace player {

    DataModelException::DataModelException(const std::string& cause):
      core::OgameException(cause)
    {
      //ctor
    }

    DataModelException::~DataModelException()
    {
      //dtor
    }

  }
}
