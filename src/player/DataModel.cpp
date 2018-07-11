
#include "DataModel.h"

namespace ogame {
  namespace player {

    DataModel::DataModel(const View& initView):
      m_activeView(initView),
      m_listeners()
    {
      // Nothing to do here.
    }

    DataModel::~DataModel() {}

    void DataModel::triggerActiveViewModification(const View& view) {}

  }
}
