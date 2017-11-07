////// CLASS FOR ODE ///////////////

#include "ODE.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

// double ODE::InputValuesRK4(double& tmax, double& tmin, double& yinit, int& Nsteps, char type_){
  
//   do{
//     std::cin.clear();
//     std::cout << "Enter the domains intial and final values separated by space" << std::endl;
//     std::cin >> tmin >> tmax;
//     std::cout << "You have enterd " << tmin << ' ' << tmax << std::endl;
//     std::cout << "If these values are correct then press y else n " << std::endl;
//     std::cin >> type_;
//   }while(type_ == 'n'); /// loops continue to run untill condition satisfied
  
//   do{
//     std::cin.clear();
//     std::cout << "Enter the inital value of function" << std::endl;
//     std::cin >> yinit;
//     std::cout << "You have entered " << yinit << std::endl;
//     std::cout << "If these values are correct then press y else n " << std::endl;
//     std::cin >> type_;
//   }while(type_ == 'n'); /// loops continue to run untill condition satisfied

//   do{
//     std::cin.clear();
//     std::cout <<"Enter the number steps to be taken to reach the final solution" << std::endl;
//     std::cin >> Nsteps;
//     std::cout << "You have enterd " << Nsteps << std::endl;
//     std::cout << "If these values are correct then press y else n " << std::endl;
//     std::cin >> type_;
//   }while(type_ == 'n'); /// loops continue to run untill condition satisfied
  
//   return 0;
// }

// double ODE::InputFunction(double t, double y = 0){
//   return exp(t);
// }

double ODE::InputValuesRKF(double& tmax, double& tmin, double& yinit, int& Nsteps, double& tol , double& hmax, double& hmin, char type_){
  
  do{
    std::cin.clear();
    std::cout << "Enter the domains intial and final values separated by space" << std::endl;
    std::cin >> tmin >> tmax;
    std::cout << "You have enterd " << tmin << ' ' << tmax << std::endl;
    std::cout << "If these values are correct then press y else n " << std::endl;
    std::cin >> type_;
  }while(type_ == 'n'); /// loops continue to run untill condition satisfied
  
  do{
    std::cin.clear();
    std::cout << "Enter the inital value of function" << std::endl;
    std::cin >> yinit;
    std::cout << "You have entered " << yinit << std::endl;
    std::cout << "If these values are correct then press y else n " << std::endl;
    std::cin >> type_;
  }while(type_ == 'n'); /// loops continue to run untill condition satisfied

  do{
    std::cin.clear();
    std::cout <<"Enter the number steps to be taken to reach the final solution" << std::endl;
    std::cin >> Nsteps;
    std::cout << "You have enterd " << Nsteps << std::endl;
    std::cout << "If these values are correct then press y else n " << std::endl;
    std::cin >> type_;
  }while(type_ == 'n'); /// loops continue to run untill condition satisfied
  
  do{
    std::cin.clear();
    std::cout << "Enter the tolerance for convergence" << std::endl;
    std::cin >> tol;
    std::cout << "You have entered " << tol << std::endl;
    std::cout << "If these values are correct then press y else n " << std::endl;
    std::cin >> type_;
  }while(type_ == 'n'); /// loops continue to run untill condition satisfied

  do{
    std::cin.clear();
    std::cout <<"Enter the maximum and minimum size of increment step to be taken separated by space" << std::endl;
    std::cin >> hmax >> hmin;
    std::cout << "You have enterd " << hmax << ' ' << hmin << std::endl;
    std::cout << "If these values are correct then press y else n " << std::endl;
    std::cin >> type_;
  }while(type_ == 'n'); /// loops continue to run untill condition satisfied
  
  return 0;
}

void ODE::RK4(std::vector<double>& w1, double tmax, double tmin, double yinit, int Nsteps){
  //  InputValuesRK4(tmax, tmin, yinit, Nsteps, type_);
  w1.resize(Nsteps+1);
  std::cout << "size from RK4 " << w1.size() << std::endl;
  double t = tmin;
  double k1,k2,k3,k4;
  w1[0] = yinit;
  h = (tmax - tmin)/Nsteps;
  for (int i = 1; i <Nsteps + 1; ++i ){
    k1 = h*InputFunction(t,w1[i-1]);
    k2 = h*InputFunction(t + 0.5*h,w1[i-1] + 0.5*k1);
    k3 = h*InputFunction(t + 0.5*h,w1[i-1] + 0.5*k2);
    k4 = h*InputFunction(t + h,w1[i-1] + k3);
    
    w1[i]  = w1[i-1] + ((k1 + 2*k2 + 2*k3 + k4)/6.0);
    t = t + h;
    
    //    std::cout << std::setw(15) << std::left << t << std::setw(15) << std::left << w1[i] << std::setw(15) << std::left << h << std::endl; // output of the results 
  }
  std::cout << "The procedure is completed " << std::endl;
  
};

void ODE::RKF(std::vector<double>& woo, std::vector<double>& hsteps, double tmax, double tmin, double yinit, int Nsteps, double tol , double hmax, double hmin){
  //  InputValuesRKF(tmax, tmin, yinit, Nsteps, tol, hmax, hmin, type_);
  double t = tmin, w = yinit, h = hmax;
  int flag = 1;
  double k1,k2,k3,k4,k5,k6,R,delta;
  woo.resize(0);
  hsteps.push_back(h);
  woo.push_back(w);
  while (flag == 1 ){
    k1 = h*InputFunction(t,w);
    k2 = h*InputFunction(t + 0.25*h,w + 0.25*k1);
    k3 = h*InputFunction(t + (3.0/8.0)*h,w + (3.0/32.0)*k1 + (9.0/32.0)*k2);
    k4 = h*InputFunction(t + (12.0/13.0)*h,w + (1932.0/2197.0)*k1 - (7200.0/2197.0)*k2 + (7296.0/2197.0)*k3);
    k5 = h*InputFunction(t + h, w + (439.0/216.0)*k1 - 8.0*k2 + (3680.0/513.0)*k3 - (845.0/4104.0)*k4);
    k6 = h*InputFunction(t + 0.5*h, w - (8.0/27.0)*k1 + 2.0*k2 - (3544.0/2565.0)*k3 + (1859.0/4104.0)*k4 - (11.0/40.0)*k5);
    
    R = (1/h)*fabs((1.0/360.0)*k1 - (128.0/4275.0)*k3 - (2197.0/75240.0)*k4 + (1.0/50.0)*k5 + (2.0/55.0)*k6);
    
    if (R <= tol){
      t = t + h;
      w = w + (25.0/216.0)*k1 + (1408.0/2565.0)*k3 + (2197.0/4104.0)*k4 - 0.20*k5;
    }
    delta = 0.84*(pow((tol/R),0.25));
    if (delta <= 0.1)
      h = 0.1*h;
    else if (delta >= 4.0)
      h = 4.0*h;
    else
      h = delta*h;

    if (h > hmax) h = hmax;

    if (t >= tmax )
      flag = 0;
    else if (t + h > tmax)
      h = tmax - t;
    else if (h < hmin){
      flag = 0;
      std::cout << " minimum h exceeded \n" << "Procedure completed successfully." << std::endl;
    }
    //    std::cout << std::setw(15) << std::left << t << std::setw(15) << std::left << w << std::setw(15) << std::left << h << std::endl;
    hsteps.push_back(h);
    woo.push_back(w);
  }
  std::cout << "The procedure is completed " << std::endl;
};

void ODE::AdamBashforthOpen(std::vector<double>& w1, double tmax, double tmin, double yinit, int Nsteps, int order){
  double tmax_ = tmin + ((order-1)*(tmax - tmin)/Nsteps);
  std::vector<double> coefficients {3.0/2.0, -1.0/2.0, 0, 0, 0, 23.0/12.0, -16.0/12.0, 5.0/12.0, 0 , 0, 55.0/24.0, -59.0/24.0, 37.0/24.0, -9.0/24.0, 0, 1901.0/720.0, -2774.0/720.0, 2616.0/720.0, -1274.0/720.0, 251.0/720.0};
  if (w1.size() < order)  RK4(w1, tmax_, tmin, yinit, order-1);
  //// read coefficients from the file ////
  double t = tmax_;
  double w = 0;
  for (int i=order-1; i < Nsteps; ++i){
    w = 0.0;
    for (int j = 1; j<=order; ++j){
      w = w + h*coefficients[(order-2)*5 + j - 1]*InputFunction(t-((j-1)*h),w1[i-(j-1)]);
      std::cout << " " << ' ' << (order-2)*5 + j - 1 << " " << t-((j-1)*h) << " " << i-(j-1) << std::endl;
    }
    t = t+h;
    w1.push_back(w1[i] + w);
    //   std::cout << i+1<< " = "  << w1[i+1] << " t = " << t << std::endl;
  }
}

void ODE::AdamBashforthOpenForImplicit(std::vector<double>& w1, double tmin, double step_size, double yinit, int order, int current_step){
  std::vector<double> coefficients {3.0/2.0, -1.0/2.0, 0, 0, 0, 23.0/12.0, -16.0/12.0, 5.0/12.0, 0 , 0, 55.0/24.0, -59.0/24.0, 37.0/24.0, -9.0/24.0, 0, 1901.0/720.0, -2774.0/720.0, 2616.0/720.0, -1274.0/720.0, 251.0/720.0};
  double tmax_ = 0, t = 0, w = 0;
  if (w1.size() < order) {
    tmax_ = tmin + ((order-1)*step_size);
    RK4(w1, tmax_, tmin, yinit, order-1);
  }
  //// read coefficients from the file ////
  w = 0.0;
  t = tmin + current_step*step_size;
  for (int j = 1; j<=order; ++j){
    w = w + step_size*coefficients[(order-2)*5 + j - 1]*InputFunction(t-((j-1)*step_size),w1[current_step-j]);
    std::cout << " " << ' ' << (order-2)*5 + j - 1 << " " << t-((j-1)*step_size) << " " << current_step - j << std::endl;
  }
  w1.push_back(w1[current_step] + w);
    //   std::cout << i+1<< " = "  << w1[i+1] << " t = " << t << std::endl;
}

void ODE::AdamBashforthClosed(std::vector<double>& w1, double tmax, double tmin, double yinit, int Nsteps, int order){
  std::vector<double> coefficients {1.0/2.0 ,1.0/2.0 , 0, 0, 0, 0, 5.0/12.0, 8.0/12.0, -1.0/12.0, 0 , 0, 0, 9.0/24.0, 19.0/24.0, -5.0/24.0, 1.0/24.0, 0, 0, 251.0/720.0, 646.0/720.0, -264.0/720.0, 106.0/720.0, -19.0/720.0, 0, 475.0/1440.0, 1427.0/1440.0, -798.0/1440.0, 482.0/1440.0, -173.0/1440.0, 27.0/1440.0};
  double step_size = (tmax - tmin)/Nsteps;
  ///  RK4(w1, tmax_, tmin, yinit, order-1);
  //// read coefficients from the file ////
  double t = tmin + order*step_size;
  double w = 0;
  for (int i=order; i < Nsteps+1; ++i){
    AdamBashforthOpenForImplicit(w1, tmin, step_size, yinit, order, i);
    w = 0.0;
    for (int j = 1; j<=order; ++j){
      w = w + h*coefficients[(order-2)*5 + j - 1]*InputFunction(t-((j-1)*h),w1[i-(j-1)]);
      std::cout << " " << ' ' << (order-2)*5 + j - 1 << " " << t-((j-1)*h) << " " << i-(j-1) << std::endl;
    }
    t = t+step_size;
    w1.push_back(w1[i] + w);
    //   std::cout << i+1<< " = "  << w1[i+1] << " t = " << t << std::endl;
  }
}
