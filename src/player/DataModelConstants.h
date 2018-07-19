#ifndef DATAMODELCONSTANTS_H
#define DATAMODELCONSTANTS_H

namespace ogame {
  namespace player {

    // Enumeration to describe available actions.
    enum class Action {
      None,
      ChangeView,
      ChangePlanet,
      ChangeAccount,
      ChangeGalaxy,
      ChangeSystem
    };

    // Enumeration to describe available views.
    enum class View {
      Overview,
      Resources,
      Facilities,
      Research,
      Shipyard,
      Defense,
      Fleet,
      Galaxy,
      Alliance
    };

  }
}

#endif // DATAMODELCONSTANTS_H
