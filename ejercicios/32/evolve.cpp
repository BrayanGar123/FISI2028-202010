#include <iostream>
#include <fstream>
#include <cmath>
#include "stdio.h"

void init(double *psi, double delta_x, int n_x);
void print(double *psi, int n_x);
void copy(double *recibe, double *entrega, int n_x);
void evolve(double *psi_future, double *psi_present, double *psi_past, double delta_t, double delta_x, double c, int n_x);
void evolve_first(double *psi_future, double *psi_present, double *psi_past, double delta_t, double delta_x, double c, int n_x);

int main(int argc, char **argv){
  double *psi_past = NULL;
  double *psi_present = NULL;
  double *psi_future = NULL;
  int n_x;
  int n_t;
  int n;  
  double t_max=0.1;
  double delta_t ;
  double delta_x ;
  double ten = 40.0;
  double rho = 0.01;
  double c = sqrt(ten/rho);
  double L = 1.0;

  n_x = atoi(argv[1]);
  n_t = atoi(argv[2]);

  delta_x = L/(n_x-1);
  delta_t = t_max/(n_t-1);

  psi_past  = new double [n_x];
  psi_present  = new double [n_x];
  psi_future  = new double [n_x];

  init(psi_past, delta_x, n_x);
  init(psi_present, delta_x, n_x);

  print(psi_past, n_x);
  evolve_first(psi_future, psi_present, psi_past, delta_t, delta_x, c, n_x);  
  print(psi_present, n_x);

  for(n=1;n<n_t-1;n++){
    evolve(psi_future, psi_present, psi_past, delta_t, delta_x, c, n_x);  
    print(psi_future, n_x);
    copy(psi_past, psi_present, n_x);
    copy(psi_present, psi_future, n_x);
  }

  return 0;
}


void init(double *psi, double delta_x, int n_x){
  int i;
  double L = delta_x * (n_x - 1);
  double pi = 3.141592653589;
  for(i=0;i<n_x;i++){
    psi[i] = 0.0001 * sin(2.0 * pi * i * delta_x/L);
  }
}

void evolve(double *psi_future, double *psi_present, double *psi_past, double delta_t, double delta_x, double c, int n_x){
  int i;
  double c_prime = delta_x/delta_t;
  for(i=1;i<n_x-1;i++){
    psi_future[i] = 2.0 * psi_present[i] - psi_past[i];
    psi_future[i] += (c * c ) / (c_prime * c_prime) * (psi_present[i+1] + psi_present[i-1] - 2.0*psi_present[i]);
  }  
}

void evolve_first(double *psi_future, double *psi_present, double *psi_past, double delta_t, double delta_x, double c, int n_x){
  int i;
  double c_prime = delta_x/delta_t;
  for(i=1;i<n_x-1;i++){
    psi_present[i] = psi_past[i] + 0.5*(c * c)/(c_prime * c_prime) * (psi_past[i+1] + psi_past[i-1] - 2.0*psi_past[i]);    
  }  
}

void copy(double *recibe, double *entrega, int n_x){
  int i;
  for (i=0;i<n_x;i++){
    recibe[i] = entrega[i];
  }
}



void print(double *psi, int n_x){
  int i;
  for(i=0;i<n_x;i++){
    std::cout << psi[i] << " ";
  }
  std::cout << "\n";
}


