#ifndef PY_DG_TEST_PENDULUM_HH
#define PY_DG_TEST_PENDULUM_HH

#include <dynamic-graph/entity.h>
#include <dynamic-graph/signal-ptr.h>
#include <dynamic-graph/linear-algebra.h>

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

      void incr(double inTimeStep);

      std::shared_ptr<const SignalPtr<double, int> > getForce() const;
      std::shared_ptr<const Signal<Vector, int> > getState() const;

    protected:
      static const std::string CLASS_NAME;

    private:
      double cartMass_;
      double pendulumMass_;
      double pendulumLength_;
      double viscosity_;

      std::shared_ptr<SignalPtr<double, int> > forceSIN;
      std::shared_ptr<Signal<Vector, int> > stateSOUT;

      Vector computeDynamics(const Vector& inState, const double& inControl, double& inTimeStep);

  };
}


#endif
