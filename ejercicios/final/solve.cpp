#include <iostream>
#include <cmath>

using namespace std;

void inicial(double *u, double min_x, double delta_x, int n);
void evoluciona(double *u_new, double *u_old, int n, double delta_x, double delta_t, double c);
void copia(double *u_new, double *u_old, int n);
void imprime(double *u, double min_x, double delta_x, int n, double t);

void inicial(double *u, double min_x, double delta_x, int n){
  int i;
  double x;
  for(i=0;i<n;i++){
    x = min_x +  i * delta_x;
    u[i] = exp(-pow((x-1.0)/0.25,2)*0.5);
  }
}
void imprime(double *u, double min_x, double delta_x, int n, double t){
  int i;
  double x;
  for(i=0;i<n;i++){
    x = min_x +  i * delta_x;
    cout << t << " " << x << " " << u[i] << endl;
  }
}

// Esto usa un esquema forward difference para la derivada temporal y backward difference para la derivada espacial
void evoluciona(double *u_new, double *u_old, int n, double delta_x, double delta_t, double c){
  int i;
  for(i=1;i<n-1;i++){
    u_new[i] = u_old[i] - u_old[i]*(delta_t/delta_x)*(u_old[i] - u_old[i-1]);
  }
}

void copia(double *u_new, double *u_old, int n){
  int i;
  for(i=0;i<n;i++){
    u_new[i] = u_old[i];
  }
}

int main(){
  double min_x=0.0, max_x=2.0, delta_x=0.01;
  int n_x = (max_x - min_x)/delta_x + 1;
  double delta_t = 0.01, T=0.5, t=0.0;
  double c=1.0;
  double * u_old, *u_new;
   
  u_old = new double[n_x];
  u_new = new double[n_x];
  
  inicial(u_old, min_x, delta_x, n_x);
  imprime(u_old, min_x, delta_x, n_x, t);
  while(t<T){
    evoluciona(u_new, u_old, n_x, delta_x, delta_t, c);
    copia(u_old, u_new, n_x);
    t += delta_t;
  }
  imprime(u_old, min_x, delta_x, n_x, t);
  return 0;
}
