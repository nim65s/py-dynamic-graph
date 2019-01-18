#include <boost/python.hpp>
#include <py-dynamic-graph/py-dynamic-graph.hpp>

#include "pendulum.hpp"

BOOST_PYTHON_MODULE(libpy_pendulum)
{
  using namespace boost::python;
  using namespace dynamicgraph;

  expose_entity();

  class_<InvertedPendulum, bases<Entity>, boost::noncopyable>("InvertedPendulum", init<std::string, optional<double, double, double, double> >())
    .add_property("cart_mass", &InvertedPendulum::getCartMass, &InvertedPendulum::setCartMass)
    .add_property("pendulum_mass", &InvertedPendulum::getPendulumMass, &InvertedPendulum::setPendulumMass)
    .add_property("pendulum_length", &InvertedPendulum::getPendulumLength, &InvertedPendulum::setPendulumLength)
    .add_property("viscosity", &InvertedPendulum::getViscosity, &InvertedPendulum::setViscosity)
    ;
}
