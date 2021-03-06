#include <py-dynamic-graph/py-dynamic-graph.hpp>

namespace dynamicgraph
{
  using namespace boost::python;

  void translate(ExceptionSignal const& e)
  {
    PyErr_SetString(PyExc_RuntimeError, e.getExceptionName().c_str());
  }

  // TODO void expose_signal<T, Time>()
  void expose_signal_base()
  {

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
      //.def(str(self))
      ;

    class_<Signal<T, Time>, bases<SignalBase<Time> >, boost::noncopyable>("Signal", init<std::string>())
      ;

    class_<SignalPtr<T, Time>, bases<Signal<T, Time> >, boost::noncopyable>("SignalPtr", init<Signal<T, Time>*, std::string>())
      ;


  }

  void register_types()
  {

    register_ptr_to_python< std::shared_ptr<SignalBase<Time> const > >();

    register_ptr_to_python< std::shared_ptr<Signal<double, Time> const > >();
    register_ptr_to_python< std::shared_ptr<Signal<Vector, Time> const > >();

    register_ptr_to_python< std::shared_ptr<SignalPtr<double, Time> const > >();
    register_ptr_to_python< std::shared_ptr<SignalPtr<Vector, Time> const > >();
  }

  //void expose_signal()
  //{
    //class_<Signal<Vector, Time>>("Signal", init<std::string>());
  //}
}
