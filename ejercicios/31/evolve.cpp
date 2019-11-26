#include <iostream>
#include <fstream>
#include <cmath>
#include "stdio.h"


void init(double *psi, int n_x);
void print(double *psi, int n_x);
void copy(double *recibe, double *entrega, int n_x);
void evolve(double *psi_new, double *psi_old, double delta_t, double delta_x, int n_x);
double difference(double *psi_new, double *psi_old, int n_x);

int main(int argc, char **argv){
  double *psi = NULL;
  double *psi_past = NULL;
  int n_x;
  int n_t=0;
  int n;
  double t_max=1.0;
  double delta_x ;
  double delta_t ;
  double diff=1.0;

  n_x=atoi(argv[1]);

  delta_x = 2.0/n_x;
  delta_t = 0.5 * delta_x * delta_x;
  
  psi  = new double [n_x];
  psi_past  = new double [n_x];

  init(psi, n_x);
  //  print(psi, n_x);
  
  while(diff > 1E-6){
    copy(psi_past, psi, n_x);
    evolve(psi, psi_past, delta_t, delta_x, n_x);
    //    print(psi, n_x);
    diff = difference(psi, psi_past, n_x);
    n_t += 1;
  }
  std::cout << n_x << " " << n_t << " " << std::abs(psi[n_x/2]+0.5)/0.5 << " "<< diff << std::endl;

  return 0;
}

double difference(double *psi_new, double *psi_old, int n_x){
  int i;
  double max_psi=0;
  double delta_psi=0;
  for(i=0;i<n_x;i++){
    if(std::abs(psi_new[i] - psi_old[i])>delta_psi){
      delta_psi = std::abs(psi_new[i] - psi_old[i]);
      max_psi = std::abs(psi_old[i]);
    }
  }

  return delta_psi/max_psi;
}

void evolve(double *psi_new, double *psi_old, double delta_t, double delta_x, int n_x){
  int i;
  double s=-1.0;
  for(i=1;i<n_x-1;i++){
    psi_new[i] = psi_old[i];
    psi_new[i] += (delta_t/(delta_x * delta_x)) * (psi_old[i+1]-2*psi_old[i] + psi_old[i-1]);
    psi_new[i] += delta_t * s;
  }
  
}

void copy(double *recibe, double *entrega, int n_x){
  int i;
  for (i=0;i<n_x;i++){
    recibe[i] = entrega[i];
  }
}

void init(double *psi, int n_x){
  int i;
  for(i=0;i<n_x;i++){
    psi[i] = 0.0;
  }
}


void print(double *psi, int n_x){
  int i;
  for(i=0;i<n_x;i++){
    std::cout << psi[i] << " ";
  }
  std::cout << "\n";
}


