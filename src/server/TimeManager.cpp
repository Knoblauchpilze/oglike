
#include "TimeManager.h"

namespace ogame {
  namespace server {
    namespace time {

      const float TimeManager::sk_defaultDurationsBufferLength(10);

      TimeManager::TimeManager(const float& initialTime, const Unit& unit) :
        m_unit(unit),
        m_time(initialTime),
        m_lastDurations()
      {
          // Nothing to do
      }

      TimeManager::~TimeManager() {
        // Nothing to do
      }

      float TimeManager::convertDuration(const float& duration, const Unit& initialUnit, const Unit& targetUnit) {
        // Convert the source into seconds
        float sourceToSeconds(1.0f);
        switch (initialUnit) {
        case Unit::Millisecond:
          sourceToSeconds = 0.001f;
          break;
        case Unit::Second:
          sourceToSeconds = 1.0f;
          break;
        case Unit::Minute:
          sourceToSeconds = 60.0f;
          break;
        case Unit::Hour:
          sourceToSeconds = 60.0f * 60.0f;
          break;
        case Unit::Day:
          sourceToSeconds = 60.0f * 60.0f * 24.0f;
          break;
        default:
            // Assume it is second
            break;
        }
        float secondsDuration = duration * sourceToSeconds;
        // Convert back into desired unit
        float secondsToTarget(1.0f);
        switch (targetUnit) {
        case Unit::Millisecond:
          secondsToTarget = 1.0f / 0.001f;
          break;
        case Unit::Second:
          secondsToTarget = 1.0f / 1.0f;
          break;
        case Unit::Minute:
          secondsToTarget = 1.0f / 60.0f;
          break;
        case Unit::Hour:
          secondsToTarget = 1.0f / (60.0f * 60.0f);
          break;
        case Unit::Day:
          secondsToTarget = 1.0f / (60.0f * 60.0f * 24.0f);
          break;
        default:
            // Assume it is second
            break;
        }
        return secondsDuration * secondsToTarget;
      }

    }
  }
}
