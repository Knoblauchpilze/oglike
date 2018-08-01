#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <vector>
#include <memory>

namespace ogame {
  namespace server {
    namespace time {

      enum class Unit {
        Nanosecond,
        Millisecond,
        Second,
        Minute,
        Hour,
        Day
      };

      class TimeManager
      {
        public:

          TimeManager(const float& initialTime = 0.0f, const Unit& unit = Unit::Second);

          ~TimeManager();

          void increment(const float& time, const Unit& unit = Unit::Second);

          void decrement(const float& time, const Unit& unit = Unit::Second);

          float getLastStepDuration(const Unit& unit = Unit::Second) const;

          float getDurationSinceLaunch(const Unit& unit = Unit::Second) const;

        private:

          void handleTimeModification(const Unit& unit, const float& duration);

          static float convertDuration(const float& duration, const Unit& initialUnit, const Unit& targetUnit);

        private:

          static const float sk_defaultDurationsBufferLength;

          Unit m_unit;
          float m_time;

          std::vector<std::pair<Unit, float>> m_lastDurations;
      };

      using TimeManagerShPtr = std::shared_ptr<TimeManager>;
    }
  }
}

#include "TimeManager.hxx"

#endif // TIMEMANAGER_H
