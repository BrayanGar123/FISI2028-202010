#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void initialize_state(float *s);
void evolve_state_rk4(float g, float friccion, float delta_t, float *s);
void solve(float g, float friccion, float delta_t, float t_max, string filename);
void derivative(float g, float friccion, float *d, float *s);

int main(){
  float delta_t=0.01;
  float t_max =2.0;
  float g=9.8;
  solve(g, 0.0,  delta_t, t_max, "sin_friccion.dat");
  solve(g, 0.7,  delta_t, t_max, "con_friccion.dat");
  return 0;
}

void initialize_state(float *s){
  s[0] = 0.0; //posicion x
  s[1] = 0.0; //posicion y
  s[2] = 10.0; //velocidad x
  s[3] = 10.0; //velocidad y
}

void derivative(float g, float friccion, float *d, float *s){
  // derivada de la posicion x es la velocidad x
  d[0] = s[2];
  
  // derivada de la posicion y es la velocidad y
  d[1] = s[3];

  // derivada de la velocidad x es la aceleracion en x
  d[2] = -friccion * s[2] * s[2] / sqrt(s[2]*s[2] + s[3]*s[3]);

  // derivada de la veolcidad y es la aceleracion en y;
  d[3] = -g - (friccion * s[3] * s[3] / sqrt(s[2]*s[2] + s[3]*s[3]));
}

void evolve_state_rk4(float g, float friccion, float delta_t, float *s){
  float d1[4];
  float d2[4];
  float d3[4];
  float d4[4];
  float d[4];
  float tmp_s[4];
  int i;
  
  /*primer paso RK*/
  for(i=0;i<4;i++){
    tmp_s[i] = s[i];
  }  
  derivative(g, friccion, d1, tmp_s);  
  
  /*segundo paso RK*/
  for(i=0;i<4;i++){
    tmp_s[i] = s[i] + 0.5 * delta_t * d1[i];
  }  
  derivative(g, friccion, d2, tmp_s);  

  /*tercer paso RK*/
  for(i=0;i<4;i++){
    tmp_s[i] = s[i] + 0.5 * delta_t * d2[i];
  }  
  derivative(g, friccion, d3, tmp_s);  

  /*cuarto paso RK*/
  for(i=0;i<4;i++){
    tmp_s[i] = s[i] + delta_t * d3[i];
  }  
  derivative(g, friccion, d4, tmp_s);  

  /*promedia las cuatro derivadas*/
  for(i=0;i<4;i++){
    d[i] = (d1[i] + 2.0 * d2[i] + 2.0 * d3[i] + d4[i])/6.0;
  }  

  /*da el paso final*/
  for(i=0;i<4;i++){
    s[i] = s[i] + d[i]*delta_t;
  }  

}

void solve(float g, float friccion, float delta_t, float t_max, string filename){
  float t=0;
  float state[4];
  ofstream outfile;
  outfile.open(filename);

  initialize_state(state);
  while(t < t_max){
    evolve_state_rk4(g, friccion, delta_t, state);
    outfile << state[0] << " " << state[1] << " "<< state[2] << " "<< state[3] << "\n";
    t = t+delta_t;    
  }
  outfile.close();
}


