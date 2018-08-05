#ifndef UNIVERSERUNNABLE_H
#define UNIVERSERUNNABLE_H

#include <memory>
#include "Runnable.h"
#include "Universe.h"
#include "DataModelImplementation.h"

namespace ogame {
  namespace server {

    class UniverseRunnable: public Runnable
    {
      public:

        UniverseRunnable(core::UniverseShPtr universe,
                         player::GeneralDataModelShPtr model);

        virtual ~UniverseRunnable();

        void simulate(const time::TimeManager& manager) override;

      private:

        void updatePlanetsForUniverse(const float& hoursDuration);

        const bool updateResourcesForPlanet(core::Planet& planet, const float& hoursDuration);

        const bool updateUpgradeActionsForPlanet(core::Planet& planet, bool* actionFinished);

        const bool updateBuildingActionsForPlanet(core::Planet& planet, bool* actionFinished);

        const bool updateShipActionsForPlanet(core::Planet& planet, bool* actionFinished);

        const bool updateDefenseActionsForPlanet(core::Planet& planet, bool* actionFinished);

        const bool updateFleetsForPlanet(core::Planet& planet, bool* actionFinished);

        void updateAccountsForUniverse();

        const bool updateUpgradeActionsForAccount(core::Account& account, bool* actionFinished);

      private:

        core::UniverseShPtr m_universe;
        player::GeneralDataModelShPtr m_model;

    };

    using UniverseRunnableShPtr = std::shared_ptr<UniverseRunnable>;
  }
}

#include "UniverseRunnable.hxx"

#endif // UNIVERSERUNNABLE_H