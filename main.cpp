
//////////////////////////////////////////////////////////////////////////////////////////////////
//// THIS IS MAIN PROGRAM FOR CALLING THE RK4 FUNCTION IN CLASS ODE, WHICH WILL BE EXPANDED  /////
//// FURTHER ASSIGNMENTS /////////////////////////////////////////////////////////////////////////
//// THE INPUT FUNCTION SHOULD BE DEFINED IN FILE InputFunction.cpp //////////////////////////////
//// When compiling use the command g++* ODE.hpp ODE.cpp InputFunction.cpp main.cpp -o prog.o ////
//// where "*" refers to the version of gcc and prog.o name of object file ///////////////////////
//// WRITER: MANOJ DHIMAN(2016MEZ0021)////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

#include "ODE.hpp" // including class ODE
#include <iostream>
#include <iterator>
#include <iomanip>
int main(){
  std::vector<double> woo, hsteps;
  ODE ode_; // declaring object ode_ of class type ODE
  // std::cout << "RESULTS FROM RK4 " << std::endl;
  // ode_.RK4(woo,2,0,0.5,10); // using the method RK4
  //   std::copy(woo.begin(), woo.end(),
  // 	      std::ostream_iterator<double>(std::cout << std::setprecision(15), " "));
  // std::cout << "RESULTS FROM RKF " << std::endl;
  // ode_.RKF(woo,hsteps,2,0,0.5,10, 0.00001, 0.25, 0.01);
  // std::copy(woo.begin(), woo.end(),
  // 	    std::ostream_iterator<double>(std::cout, " "));
  // std::copy(hsteps.begin(), hsteps.end(),
  // 	    std::ostream_iterator<double>(std::cout, " "));
  // std::cout << "RESULTS FROM AdamBashforth " << std::endl;
  // ode_.AdamBashforthOpen(woo,2,0,0.5,10,4); // using the method RK4 
  std::cout << "RESULTS FROM AdamBash Forth Implicit " << std::endl;
  ode_.AdamBashforthOpen(woo,2,0,0.5,10,4); // using the method RK4
  std::copy(woo.begin(), woo.end(),
              std::ostream_iterator<double>(std::cout, " "));
  return 0;
}








