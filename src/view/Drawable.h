#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SDL/SDL.h>
#include <mutex>
#include "Area.h"

namespace ogame {
  namespace view {

    class Drawable
    {
      public:

        virtual bool tryLock();

        virtual void lock();

        virtual void unlock();

        virtual utils::Area getRenderingArea() = 0;

        virtual SDL_Surface* draw() = 0;

      protected:

        Drawable();

        virtual ~Drawable();

        //  We assume that the object is already locked upon entering this function.
        virtual bool hasChanged() const noexcept = 0;

      private:

        std::mutex m_locker;
    };

  }
}

#endif // DRAWABLE_H
