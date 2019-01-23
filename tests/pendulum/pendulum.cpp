#include <iostream>

#include <dynamic-graph/factory.h>

#include "pendulum.hpp"

namespace dynamicgraph {
  DYNAMICGRAPH_FACTORY_ENTITY_PLUGIN(InvertedPendulum, "InvertedPendulum");

  InvertedPendulum::InvertedPendulum(const std::string& inName, double cartMass,
      double pendulumMass, double pendulumLength, double viscosity):
    Entity(inName), cartMass_(cartMass), pendulumMass_(pendulumMass),
    pendulumLength_(pendulumLength), viscosity_(viscosity),
    forceSIN(new SignalPtr<double, int>(NULL, "InvertedPendulum("+inName+"::input(double)::force")),
    stateSOUT(new Signal<Vector, int>("InvertedPendulum("+inName+"::output(vector)::state"))
  {
    signalRegistration(*forceSIN);
    signalRegistration(*stateSOUT);
    double input = 0.;
    forceSIN->setConstant(input);
    Vector state(4);
    state.fill(0.1);
    stateSOUT->setConstant(state);
  }

  Vector InvertedPendulum::computeDynamics(const Vector& inState, const double& inControl, double& inTimeStep)
  {
    assert(inState.size() == 4);

    double dt = inTimeStep;
    double dt2 = dt*dt;
    double g = 9.81;
    double x = inState(0);
    double th = inState(1);
    double dx = inState(2);
    double dth = inState(3);
    double F = inControl;
    double m = pendulumMass_;
    double M = cartMass_;
    double l = pendulumLength_;
    double lambda = viscosity_;
    double l2 = l*l;
    double dth2 = dth*dth;
    double sth = sin(th);
    double cth = cos(th);
    double sth2 = sth*sth;

    double b1 = F - m*l*dth2*sth - lambda*dx;
    double b2 = m*l*g*sth - lambda*dth;

    double det = m*l2*(M + m*sth2);

    double ddx = (b1*m*l2 + b2*m*l*cth)/det;
    double ddth = ((M+m)*b2 + m*l*cth*b1)/det;

    Vector nextState(4);
    nextState(0) = x + dx*dt + .5*ddx*dt2;
    nextState(1) = th + dth*dt + .5*ddth*dt2;
    nextState(2) = dx + dt*ddx;
    nextState(3) = dth + dt*ddth;

    return nextState;
  }

  void InvertedPendulum::incr(double inTimeStep)
  {
    int t = stateSOUT->getTime();
    std::cout << stateSOUT->access(t).transpose() << std::endl;
    stateSOUT->setConstant(computeDynamics(stateSOUT->access(t), forceSIN->access(t), inTimeStep));
    stateSOUT->setTime(t+1);
    forceSIN->access(t+1);
  }

  std::shared_ptr<const SignalPtr<double, int> > InvertedPendulum::getForce() const {
    return forceSIN;
  }

  std::shared_ptr<const Signal<Vector, int> > InvertedPendulum::getState() const {
    return stateSOUT;
  }
}
