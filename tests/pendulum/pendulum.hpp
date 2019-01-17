#ifndef PY_DG_TEST_PENDULUM_HH
#define PY_DG_TEST_PENDULUM_HH

#include <dynamic-graph/entity.h>

namespace dynamicgraph {
  class InvertedPendulum : public Entity::Entity
  {
    public:
      InvertedPendulum(const std::string& inName);

      /// Each entity should provide the name of the class it belongs to
      virtual const std::string& getClassName (void) const {
        return CLASS_NAME;
      }

      /// Header documentation of the python class
      virtual std::string getDocString () const {
        return
          "Classical inverted pendulum dynamic model\n";
      }

    protected:
      static const std::string CLASS_NAME;

    private:
      double cartMass_;
      double pendulumMass_;
      double pendulumLength_;
      double viscosity_;

  };
}


#endif
