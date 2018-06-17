
#include "Planet.h"

namespace ogame {
  namespace core {

    Planet::Planet(const std::string& name):
      m_name(name)
    {
      create();
    }

    Planet::~Planet()
    {
      //dtor
    }

    void Planet::create() {
      m_resources.push_back(std::make_shared<ResourceDeposit>(std::string("Metal"), 500.0f, 10000.0f));
      m_resources.push_back(std::make_shared<ResourceDeposit>(std::string("Cristal"), 500.0f, 10000.0f));
      m_resources.push_back(std::make_shared<ResourceDeposit>(std::string("Deuterium"), 0.0f, 10000.0f));
    }

  }
}
