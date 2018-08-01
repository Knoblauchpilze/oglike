
#include <iostream>
#include <algorithm>
#include "ServerLauncher.h"

namespace ogame {
  namespace server {

    const float ServerLauncher::sk_minimumComputingTimeRemainingToSleep(3.0f);

    ServerLauncher::ServerLauncher(const float& simulationFps,
                                   const float& simulationStep,
                                   const time::Unit& unit):
      m_runnables(),
      m_simulationFps(simulationFps),
      m_timeLocker(),
      m_simulationStep(simulationStep),
      m_unit(unit),
      m_time(0.0f, unit),
      m_locker(),
      m_state(State::None),
      m_simulationThread(nullptr)
    {
        // Nothing to do.
    }

    ServerLauncher::~ServerLauncher() {
      stop();
    }

    void ServerLauncher::asynchronousRunningLoop() {
      // The simulation is now running
      m_locker.lock();
      m_state = State::Running;
      m_locker.unlock();
      
      std::cout << "[LAUNCHER] Starting environment simulation..." << std::endl;

      // Run simulation steps
      bool done(false);
      do
      {
        // Handle stop, pause and resume request
        m_locker.lock();

        if (m_state == State::PauseRequested) {
          std::cout << "[LAUNCHER] Pausing environment simulation..." << std::endl;
          m_state = State::Paused;
          m_locker.unlock();
        }
        else if (m_state == State::ResumeRequested) {
          std::cout << "[LAUNCHER] Resuming environment simulation..." << std::endl;
          m_state = State::Running;
          m_locker.unlock();
        }
        else if (m_state == State::StopRequested) {
          std::cout << "[LAUNCHER] Stopping environment simulation..." << std::endl;
          m_state = State::Stopped;
          m_locker.unlock();
          done = true;
        }
        else if (m_state == State::Running) {
          m_locker.unlock();
          runSimulationStep();
        }
        else {
          // Not handled or nothing to do (e.g. Paused).
          m_locker.unlock();
        }
      } while (!done);
    }

    void ServerLauncher::runSimulationStep() {
      // Retrieve the parameters of the current step
      std::lock_guard<std::mutex> lock(m_timeLocker);

      const float currentSimulationStepComputingDuration(1000.0f / m_simulationFps);

      // Update the time manager.
      m_time.increment(m_simulationStep, m_unit);

      // Start a timer to track the duration of the simulation.
      std::chrono::system_clock::time_point startingSimulationTime = std::chrono::system_clock::now();
      
      std::cout << "[LAUNCHER] Simulating " << m_runnables.size() << " runnables..." << std::endl;

      // Simulate the current step on each runnable.
      std::for_each(m_runnables.begin(),  m_runnables.end(),
        [this](Runnable* runnable) {
          runnable->simulate(m_time);
        }
      );

      // Compute the duration of the simulation
      const float simulationDuration = std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now() -
        startingSimulationTime
      ).count();

      // Compare with the desired frame rate and delay if needed
      if (simulationDuration > currentSimulationStepComputingDuration) {
        std::cerr << "[LAUNCHER] Frame took " << simulationDuration << "ms which is greater than the " << currentSimulationStepComputingDuration << "ms authorized to maintain " << m_simulationFps << "fps" << std::endl;
      }
      else {
        // Compute if we actually need to sleep: if there's only 1ms remaining, we might as well start the next simulation asap.
        const float remainingDuration(currentSimulationStepComputingDuration - simulationDuration);
        if (remainingDuration > sk_minimumComputingTimeRemainingToSleep) {
          std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(remainingDuration)));
        }
      }
    }

  }
}
