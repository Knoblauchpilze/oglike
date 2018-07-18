#ifndef SYSTEMCOORDINATES_H
#define SYSTEMCOORDINATES_H

#include <vector>
#include <string>
#include <memory>

namespace ogame {
  namespace core {

    class SystemCoordinates
    {
      public:

        SystemCoordinates(const unsigned& galaxy, const unsigned system);

        ~SystemCoordinates();

        const unsigned& getGalaxy() const noexcept;

        const unsigned& getSystem() const noexcept;

      private:

        unsigned m_galaxy;
        unsigned m_system;

    };

    using SystemCoordinatesShPtr = std::shared_ptr<SystemCoordinates>;

  }
}

#include "SystemCoordinates.hxx"

#endif // SYSTEMCOORDINATES_H
