#ifndef SERVERLAUNCHER_H
#define SERVERLAUNCHER_H

#include <memory>
#include <vector>
#include <mutex>
#include <thread>
#include "TimeManager.h"
#include "Runnable.h"

namespace ogame {
  namespace server {

    class ServerLauncher
    {
      public:

        ServerLauncher(const float& simulationFps,
                       const float& simulationStep,
                       const time::Unit& unit);

        virtual ~ServerLauncher();

        void addRunnable(Runnable* runnable);

        void start();

        void pause();

        void resume();

        void stop();

      private:

        void asynchronousRunningLoop();

        void runSimulationStep();

      private:

        enum class State
        {
            None,
            RunRequested,
            Running,
            PauseRequested,
            Paused,
            ResumeRequested,
            StopRequested,
            Stopped
        };

        static const float sk_minimumComputingTimeRemainingToSleep;

        std::vector<Runnable*> m_runnables;
        unsigned int m_simulationFps;
        std::mutex m_timeLocker;
        float m_simulationStep;
        time::Unit m_unit;
        time::TimeManager m_time;
        std::mutex m_locker;
        State m_state;
        std::shared_ptr<std::thread> m_simulationThread;

    };

    using ServerLauncherShPtr = std::shared_ptr<ServerLauncher>;
  }
}

#include "ServerLauncher.hxx"

#endif // SERVERLAUNCHER_H