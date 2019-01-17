#include <dynamic-graph/entity.h>
#include <boost/python.hpp>
#include <py-dynamic-graph/py-dynamic-graph.hpp>

namespace dynamicgraph
{
  void expose_entity()
  {
    using namespace boost::python;

    class_<Entity, boost::noncopyable>("Entity", init<std::string>())
      .add_property("name", make_function(&Entity::getName, return_value_policy<copy_const_reference>()))
      .add_property("class_name", make_function(&Entity::getClassName, return_value_policy<copy_const_reference>()))
      .add_property("docstring", &Entity::getDocString)
      .def("has_signal", &Entity::hasSignal)
      //.def("get_signal", &Entity::getSignal)
      //.def("display_signal_list", &Entity::displaySignalList)
      //.def(str(self))
      ;
  }
}
