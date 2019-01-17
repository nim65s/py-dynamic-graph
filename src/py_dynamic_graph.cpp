#include <boost/python.hpp>
#include <py-dynamic-graph/py-dynamic-graph.hpp>

BOOST_PYTHON_MODULE(libpy_dynamic_graph)
{
  using namespace boost::python;
  using namespace dynamicgraph;

  expose_signal_base();
  expose_entity();
}
