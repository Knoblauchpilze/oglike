#ifndef RUNNABLE_H
#define RUNNABLE_H

#include <memory>
#include "TimeManager.h"

namespace ogame {
  namespace server {

    class Runnable
    {
      public:

        Runnable();

        virtual ~Runnable();

        virtual void simulate(const time::TimeManager& manager) = 0;

    };

    using RunnableShPtr = std::shared_ptr<Runnable>;
  }
}

#endif // RUNNABLE_H