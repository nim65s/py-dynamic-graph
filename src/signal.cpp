#include <dynamic-graph/signal.h>
#include <boost/python.hpp>
#include "py_dynamic_graph.hpp"

namespace dynamicgraph
{
  typedef int Time;

  void translate(ExceptionSignal const& e)
  {
    PyErr_SetString(PyExc_RuntimeError, e.getExceptionName().c_str());
  }

  void expose_signal_base()
  {
    using namespace boost::python;

    register_exception_translator<ExceptionSignal>(&translate);

    class_<SignalBase<Time>, boost::noncopyable>("SignalBase", init<std::string>())
      .add_property("time", make_function(&SignalBase<Time>::getTime, return_value_policy<copy_const_reference>()), &SignalBase<Time>::setTime)
      .add_property("ready", make_function(&SignalBase<Time>::getReady, return_value_policy<copy_const_reference>()))
      .add_property("name", make_function(&SignalBase<Time>::getName, return_value_policy<copy_const_reference>()))
      //.add_property("class_name", &SignalBase<Time>::getClassName)
      .add_property("period_time", &SignalBase<Time>::getPeriodTime, &SignalBase<Time>::setPeriodTime)
      .def("add_dependency", &SignalBase<Time>::addDependency)
      .def("remove_dependency", &SignalBase<Time>::removeDependency)
      .def("clear_dependencies", &SignalBase<Time>::clearDependencies)
      .def("need_update", &SignalBase<Time>::needUpdate)
      .def("set_ready", &SignalBase<Time>::setReady)
      .def("plug", &SignalBase<Time>::plug)
      .def("is_plugged", &SignalBase<Time>::isPlugged)
      //.def("get_plugged", &SignalBase<Time>::getPluged)
      .def("set_constant_default", &SignalBase<Time>::setConstantDefault)
      .def("set", &SignalBase<Time>::set)
      .def("get", &SignalBase<Time>::get)
      .def("recompute", &SignalBase<Time>::recompute)
      .def("trace", &SignalBase<Time>::trace)
      .def("short_name", &SignalBase<Time>::shortName)
      //.def("extract_node_and_local_names", &SignalBase<Time>::extractNodeAndLocalNames)
      .def("check_compatibility", &SignalBase<Time>::checkCompatibility)
      ;

  }
  void expose_signal()
  {
    //class_<Signal<Vector, Time>>("Signal", init<std::string>());
  }
}
