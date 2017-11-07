////////////////////////////////////////////////////////////////
////// INPUT FUNCTION USED BY ODE CLASS ////////////////////////
////// variables used are t(independent) and y(dependent) //////
////// If your function contains different variable from above//
////// please write it in terms of above variables. ////////////
////////////////////////////////////////////////////////////////
#include <cmath>
#include "ODE.hpp"
double ODE::InputFunction(double t, double y = 0){
  return y - t*t + 1;
}
