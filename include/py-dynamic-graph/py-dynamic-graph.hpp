#ifndef PY_DYNAMIC_GRAPH_MODULE_H
#define PY_DYNAMIC_GRAPH_MODULE_H

#include <dynamic-graph/entity.h>
#include <dynamic-graph/signal-ptr.h>

#include <boost/python.hpp>
#include <boost/python/register_ptr_to_python.hpp>

namespace dynamicgraph
{

  typedef int Time;
  typedef double T;

  void expose_signal_base();
  void expose_signal();
  void expose_entity();
  void register_types();

}

#endif
