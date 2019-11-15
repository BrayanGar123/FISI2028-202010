#include <iostream>
#include <fstream>
using namespace std;

void initialize_state(float *s);
void evolve_state_rk4(float delta_t, float *s);
void solve(float delta_t, float t_max, string filename);

int main(){
  float delta_t=0.01;
  float t_max =2.0;
  solve(delta_t, t_max, "solve.dat");
  return 0;
}

void initialize_state(float *s){
  s[0] = 0.0; //posicion x
  s[1] = 0.0; //posicion y
  s[2] = 0.0; //velocidad x
  s[3] = 0.0; //velocidad y
}

void evolve_state_rk4(float delta_t, float *s){
  s[0] = 0.0;
  s[1] = 0.0;
  s[2] = 0.0;
  s[3] = 0.0;
}

void solve(float delta_t, float t_max, string filename){
  float t=0;
  float state[4];
  ofstream outfile;
  outfile.open(filename);

  initialize_state(state);
  while(t < t_max){
    evolve_state_rk4(delta_t, state);
    outfile << state[0] << " " << state[1] << " "<< state[2] << " "<< state[3] << "\n";
    t = t+delta_t;    
  }
  outfile.close();
}


