#ifndef PLANET_H
#define PLANET_H

#include <memory>
#include <string>
#include <vector>

#include "ResourceDeposit.h"
#include "Account.h"

namespace ogame {
  namespace core {

    class System;

    class Planet
    {
      public:

        Planet(const unsigned& index, const std::string& name, System* system);

        virtual ~Planet();

        bool operator==(const Planet& other) const noexcept;

        const std::string& getName() const noexcept;

        const bool isColonized() const noexcept;

        const bool hasMoon() const noexcept;

        const bool hasWreckfield() const noexcept;

        const unsigned getPositionInSystem() const;

        const unsigned& getSystemIndex() const;

        const unsigned& getGalaxyIndex() const;

        const std::string& getOwnerName() const;

        void assignToAccount(AccountShPtr account);

      protected:

        void create();

      private:

        const std::string generateRandomName(const unsigned& length) const noexcept;

      private:

        unsigned m_index;
        std::string m_name;
        System* m_parent;
        std::vector<ResourceDepositShPtr> m_resources;
        AccountShPtr m_account;
    };

    using PlanetShPtr = std::shared_ptr<Planet>;

  }
}

#include "Planet.hxx"

#endif // PLANET_H
