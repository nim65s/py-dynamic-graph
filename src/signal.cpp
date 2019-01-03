//#include <dynamic-graph/fwd.hh>

#include <dynamic-graph/signal.h>
//#include <dynamic-graph/entity.h>
//#include <dynamic-graph/linear-algebra.h>

#include <boost/python.hpp>

BOOST_PYTHON_MODULE(libpy_dynamic_graph)
{
  using namespace boost::python;
  using namespace dynamicgraph;

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

  //class_<Entity>("Entity", init<std::string>());
  //class_<Signal<Vector, int>>("Signal", init<std::string>());
}
