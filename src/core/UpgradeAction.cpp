
#include "UpgradeAction.h"

namespace ogame {
  namespace core {

    UpgradeAction::UpgradeAction(const std::chrono::system_clock::time_point& start,
                                 const Type& type,
                                 const unsigned& universeSpeed,
                                 const unsigned& shipyardLevel,
                                 const unsigned& laboratoryLevel,
                                 const unsigned& roboticsLevel,
                                 const unsigned& naniteLevel):
      m_start(start),
      m_type(type),
      m_duration(0.0f),
      m_universeSpeed(universeSpeed),
      m_shipyardLevel(shipyardLevel),
      m_laboratoryLevel(laboratoryLevel),
      m_roboticsLevel(roboticsLevel),
      m_naniteLevel(naniteLevel)
    {
      computeTotalDurationPrivate();
    }

    UpgradeAction::~UpgradeAction() {}

    void UpgradeAction::computeTotalDurationPrivate() {
      m_duration = computeTotalDuration();
    }

  }
}
