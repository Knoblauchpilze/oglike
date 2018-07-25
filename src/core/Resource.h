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

        bool operator==(const Resource& other) const noexcept;

        const std::string& getName() const;

      protected:

      private:

        std::string m_name;
    };

  }
}

#include "Resource.hxx"
#include "ResourceHashSpecialization.hxx"

#endif // RESOURCE_H
