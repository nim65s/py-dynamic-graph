#include <boost/python.hpp>
#include "py_dynamic_graph.hpp"

BOOST_PYTHON_MODULE(libpy_dynamic_graph)
{
  using namespace boost::python;
  using namespace dynamicgraph;

  expose_signal_base();
}
