//////////// HEADER FILE FOR ODE CLASS ///////////////
/// STILL UNDER DEVELOPMENT //////////////////////////

#ifndef ODE_H
#define ODE_H
#include <vector>
class ODE{
private:
  int Nsteps = 1; // default values does not effect the solution
  double tmax = 1.0, tmin = 0.0; // default values
  double h, tol, hmax, hmin; // variable for step size
  double yinit = 0.0; // arbit initialised value
  char type_;
  std::vector<double> w1;
  ///  double InputValuesRK4(double&, double&, double&, int&, char); // for getting input values
  double InputValuesRKF(double&, double&, double&, int&, double&, double&, double&, char); // for getting input values
  double InputFunction(double , double); // input function
public:
  void RK4(std::vector<double>&, double, double, double, int); // RK4 algorithm
  void RKF(std::vector<double>&, std::vector<double>&, double, double, double, int, double, double, double); // Runge-Kutta- Fehlberg algorithm
  void AdamBashforthOpen(std::vector<double>&, double, double, double, int, int);
  void AdamBashforthOpenForImplicit(std::vector<double>&, double, double, double, int, int);
  void AdamBashforthClosed(std::vector<double>&, double, double, double, int, int);
};
#endif
