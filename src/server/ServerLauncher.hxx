#ifndef SERVERLAUNCHER_HXX
#define SERVERLAUNCHER_HXX

#include "ServerLauncher.h"
#include "ServerException.h"

namespace ogame {
  namespace server {

    inline
    void ServerLauncher::addRunnable(Runnable* runnable) {
      m_runnables.push_back(runnable);
    }

    inline
    void ServerLauncher::start() {
      std::lock_guard<std::mutex> guard(m_locker);

      if (m_state == State::None || m_state == State::Stopped) {
        m_state = State::RunRequested;
        m_simulationThread = std::make_shared<std::thread>(&ServerLauncher::asynchronousRunningLoop, this);
      }
    }

    inline
    void ServerLauncher::pause() {
      std::lock_guard<std::mutex> guard(m_locker);

      if (m_state == State::Running) {
        m_state = State::PauseRequested;
      }
    }

    inline
    void ServerLauncher::resume() {
      std::lock_guard<std::mutex> guard(m_locker);

      if (m_state == State::Paused) {
        m_state = State::ResumeRequested;
      }
    }

    void ServerLauncher::stop() {
      std::lock_guard<std::mutex>lock(m_locker);

      if (m_simulationThread == nullptr) {
        if (m_state != State::None && m_state != State::Stopped) {
          // Bad state
          m_simulationThread.reset();
          throw ServerException(std::string("Cannot stop the simulation, not started"));
        }
      }
      else {
        m_state = State::StopRequested;
        m_locker.unlock();
        // Wait
        m_simulationThread->join();
        // Destroy the thread
        m_simulationThread.reset();
        // Check the execution status
        if (m_state != State::Stopped) {
            throw ServerException(std::string("Execution thread handled in error"));
        }
      }
    }

  }
}

#endif // SERVERLAUNCHER_HXX
