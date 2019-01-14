#include <dynamic-graph/signal.h>
#include <boost/python.hpp>
#include "py_dynamic_graph.hpp"

namespace dynamicgraph
{
  void expose_signal_base()
  {
    using namespace boost::python;

    class_<SignalBase<int>, boost::noncopyable>("SignalBase", init<std::string>())
      .add_property("time", make_function(&SignalBase<int>::getTime, return_value_policy<copy_const_reference>()), &SignalBase<int>::setTime)
      .add_property("ready", make_function(&SignalBase<int>::getReady, return_value_policy<copy_const_reference>()))
      .add_property("name", make_function(&SignalBase<int>::getName, return_value_policy<copy_const_reference>()))
      //.add_property("class_name", &SignalBase<int>::getClassName)
      .add_property("period_time", &SignalBase<int>::getPeriodTime, &SignalBase<int>::setPeriodTime)
      .def("add_dependency", &SignalBase<int>::addDependency)
      .def("remove_dependency", &SignalBase<int>::removeDependency)
      .def("clear_dependencies", &SignalBase<int>::clearDependencies)
      .def("need_update", &SignalBase<int>::needUpdate)
      .def("set_ready", &SignalBase<int>::setReady)
      .def("plug", &SignalBase<int>::plug)
      .def("is_plugged", &SignalBase<int>::isPlugged)
      //.def("get_plugged", &SignalBase<int>::getPluged)
      .def("set_constant_default", &SignalBase<int>::setConstantDefault)
      .def("set", &SignalBase<int>::set)
      .def("get", &SignalBase<int>::get)
      .def("recompute", &SignalBase<int>::recompute)
      .def("trace", &SignalBase<int>::trace)
      .def("short_name", &SignalBase<int>::shortName)
      //.def("extract_node_and_local_names", &SignalBase<int>::extractNodeAndLocalNames)
      .def("check_compatibility", &SignalBase<int>::checkCompatibility)
      ;

  }
  void expose_signal()
  {
    //class_<Signal<Vector, int>>("Signal", init<std::string>());
  }
}
