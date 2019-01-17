#include <dynamic-graph/factory.h>

#include "pendulum.hpp"

namespace dynamicgraph {
  DYNAMICGRAPH_FACTORY_ENTITY_PLUGIN(InvertedPendulum, "InvertedPendulum");

  InvertedPendulum::InvertedPendulum(const std::string& inName) :
    Entity(inName),
    cartMass_(1.0), pendulumMass_(1.0), pendulumLength_(1.0), viscosity_(0.1)
  {}
}
