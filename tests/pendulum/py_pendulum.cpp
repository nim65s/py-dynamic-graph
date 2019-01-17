#include <boost/python.hpp>
#include <py-dynamic-graph/py-dynamic-graph.hpp>

#include "pendulum.hpp"

BOOST_PYTHON_MODULE(libpy_pendulum)
{
  using namespace boost::python;
  using namespace dynamicgraph;

  expose_entity();

  class_<InvertedPendulum, bases<Entity>, boost::noncopyable>("InvertedPendulum", init<std::string>())
    ;
}
