#include <dynamic-graph/factory.h>

#include "pendulum.hpp"

namespace dynamicgraph {
  DYNAMICGRAPH_FACTORY_ENTITY_PLUGIN(InvertedPendulum, "InvertedPendulum");

  InvertedPendulum::InvertedPendulum(const std::string& inName, double cartMass,
      double pendulumMass, double pendulumLength, double viscosity):
    Entity(inName), cartMass_(cartMass), pendulumMass_(pendulumMass),
    pendulumLength_(pendulumLength), viscosity_(viscosity)
  {}
}
