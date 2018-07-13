#ifndef DATAMODELEXCEPTION_H
#define DATAMODELEXCEPTION_H

#include "OgameException.h"

namespace ogame {
  namespace player {

    class DataModelException: public core::OgameException
    {
      public:

        DataModelException(const std::string& cause);

        virtual ~DataModelException();

      protected:

      private:
    };

  }
}

#endif // DATAMODELEXCEPTION_H
