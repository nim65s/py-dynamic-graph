#include <py-dynamic-graph/py-dynamic-graph.hpp>

namespace dynamicgraph
{
  void expose_entity()
  {
    using namespace boost::python;
    expose_signal_base();

    class_<Entity, boost::noncopyable>("Entity", init<std::string>())
      .add_property("name", make_function(&Entity::getName, return_value_policy<copy_const_reference>()))
      .add_property("class_name", make_function(&Entity::getClassName, return_value_policy<copy_const_reference>()))
      .add_property("docstring", &Entity::getDocString)
      .def("has_signal", &Entity::hasSignal)
      .add_property("signal", make_function(&Entity::getSignal, return_value_policy<copy_const_reference>()))
      //.def("display_signal_list", &Entity::displaySignalList)
      //.def(str(self))
      ;
  }
}
