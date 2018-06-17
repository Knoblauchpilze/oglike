#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

namespace ogame {
  namespace core {

    class Resource
    {
      public:

        Resource(const std::string& name);

        virtual ~Resource();

        const std::string& getName() const;

      protected:

      private:

        std::string m_name;
    };

  }
}

#include "Resource.hxx"

#endif // RESOURCE_H
