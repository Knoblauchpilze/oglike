#ifndef UPGRADEACTION_H
#define UPGRADEACTION_H

#include <memory>

namespace ogame {
  namespace core {

    class UpgradeAction
    {
      public:

        UpgradeAction();

        virtual ~UpgradeAction();

      private:
    };

    using UpgradeActionShPtr = std::shared_ptr<UpgradeAction>;

  }
}

#include "UpgradeAction.hxx"

#endif // UPGRADEACTION_H
