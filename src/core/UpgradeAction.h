#ifndef UPGRADEACTION_H
#define UPGRADEACTION_H

#include <memory>
#include <chrono>

namespace ogame {
  namespace core {

    class UpgradeAction
    {
      public:

        virtual ~UpgradeAction();

        bool operator==(const UpgradeAction& other) const noexcept;

        const bool isFinished() const;

        // Expressed in seconds.
        const float getRemainingTime() const;

      protected:

        enum class Type {
          Building,
          Research,
          Ship,
          Defense
        };

        UpgradeAction(const std::chrono::system_clock::time_point& start,
                      const Type& type,
                      const unsigned& universeSpeed,
                      const unsigned& shipyardLevel,
                      const unsigned& laboratoryLevel,
                      const unsigned& roboticsLevel,
                      const unsigned& naniteLevel);

        virtual float computeTotalDuration() const = 0;

        const unsigned& getUniverseSpeed() const noexcept;

        const unsigned& getShipyardLevel() const noexcept;

        const unsigned& getLaboratoryLevel() const noexcept;

        const unsigned& getRoboticsLevel() const noexcept;

        const unsigned& getNaniteLevel() const noexcept;

      private:

        void computeTotalDurationPrivate();

      private:

        std::chrono::system_clock::time_point m_start;
        Type m_type;
        float m_duration;
        unsigned m_universeSpeed;
        unsigned m_shipyardLevel;
        unsigned m_laboratoryLevel;
        unsigned m_roboticsLevel;
        unsigned m_naniteLevel;

    };

    using UpgradeActionShPtr = std::shared_ptr<UpgradeAction>;

  }
}

#include "UpgradeAction.hxx"

#endif // UPGRADEACTION_H
