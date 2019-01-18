#ifndef PY_DG_TEST_PENDULUM_HH
#define PY_DG_TEST_PENDULUM_HH

#include <dynamic-graph/entity.h>

namespace dynamicgraph {
  class InvertedPendulum : public Entity::Entity
  {
    public:
      InvertedPendulum(const std::string& inName, double cartMass = 1.0, double
          pendulumMass = 1.0, double pendulumLength = 1.0, double viscosity =
          0.1);

      /// Each entity should provide the name of the class it belongs to
      virtual const std::string& getClassName (void) const {
        return CLASS_NAME;
      }

      /// Header documentation of the python class
      virtual std::string getDocString () const {
        return
          "Classical inverted pendulum dynamic model\n";
      }

      double getCartMass() const {
        return cartMass_;
      }

      void setCartMass(const double& mass) {
        cartMass_ = mass;
      }

      double getPendulumMass() const {
        return pendulumMass_;
      }

      void setPendulumMass(const double& mass) {
        pendulumMass_ = mass;
      }

      double getPendulumLength() const {
        return pendulumLength_;
      }

      void setPendulumLength(const double& length) {
        pendulumLength_ = length;
      }

      double getViscosity() {
        return viscosity_;
      }

      void setViscosity(const double& visc) {
        viscosity_ = visc;
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
