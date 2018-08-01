#ifndef TIMEMANAGER_HXX
#define TIMEMANAGER_HXX

#include "TimeManager.h"

namespace ogame {
  namespace server {
    namespace time {

      inline
      void TimeManager::increment(const float& time, const Unit& unit) {
        handleTimeModification(unit, time);
      }

      inline
      void TimeManager::decrement(const float& time, const Unit& unit) {
        handleTimeModification(unit, -time);
      }

      inline
      float TimeManager::getLastStepDuration(const Unit& unit) const {
        float lastDuration(0.0f);
        if (!m_lastDurations.empty()) {
            std::pair<Unit, float> lastStep = m_lastDurations.front();
            lastDuration = convertDuration(lastStep.second, lastStep.first, unit);
        }
        return lastDuration;
      }

      inline
      float TimeManager::getDurationSinceLaunch(const Unit& unit) const {
        return convertDuration(m_time, m_unit, unit);
      }

      inline
      void TimeManager::handleTimeModification(const Unit& unit, const float& duration) {
        float standardizedDuration = convertDuration(duration, unit, m_unit);
        m_time += standardizedDuration;
        // Add the step to the buffer
        m_lastDurations.insert(m_lastDurations.begin(), std::make_pair(unit, duration));
        if (m_lastDurations.size() > sk_defaultDurationsBufferLength) {
            m_lastDurations.pop_back();
        }
      }

    }
  }
}

#endif // TIMEMANAGER_HXX
