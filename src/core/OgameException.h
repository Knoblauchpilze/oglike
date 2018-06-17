#ifndef OGAMEEXCEPTION_H
#define OGAMEEXCEPTION_H

#include <string>
#include <stdexcept>

namespace ogame {
  namespace core {

    class OgameException: public std::exception
    {
      public:

        OgameException(const std::string& cause);

        virtual ~OgameException();

        const char* what() const throw() override;

      protected:

      private:

        std::string m_cause;
    };

  }
}

#endif // OGAMEEXCEPTION_H
