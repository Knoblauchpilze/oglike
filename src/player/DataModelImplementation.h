#ifndef DATAMODELIMPLEMENTATION_H
#define DATAMODELIMPLEMENTATION_H

#include <memory>
#include "DataModelConstants.h"
#include "AbstractDataModel.h"
#include "AbstractActionListener.h"

namespace ogame {
  namespace player {

    using GeneralDataModel = AbstractDataModel<Action>;
    using GeneralActionListener = AbstractActionListener<Action>;

    using GeneralDataModelShPtr = std::shared_ptr<GeneralDataModel>;
    using GeneralActionListenerShPtr = std::shared_ptr<GeneralActionListener>;

  }
}

#endif // DATAMODELIMPLEMENTATION_H
