/*

*/

#include <iostream>
#include <fstream>
//#include <string>
#include <math.h>

using namespace std;

const int N_iteraciones = 40;

// Multiplicar matrices
int main(void){
    // (1,2,3)
    // arreglo estático
    float z1[10]; // 32b o 4bytes
    float z2[] = {0,1,3,6,-5,2,4}; // definicion por asignación
    
    for(int a = 0; a < 10; a++)
        z1[a] = (float) 2*a;

    for(int a = 1; a < 10; a=a+2)
        cout<<"Z1["<<a<<"]: "<<z1[a]<<endl;

    // Memoria
    int j = 10;
    cout<<"la variable j = "<<j<<" y se encuentra en "<<&j<<endl;
    // vamos a crear un "apuntador" en el que vamos
    // a guardar la direccion de memoria de j
    int *k; // creando una variable k que es la referencia
    // a un sector de memoria en el que hay un entero
    k = &j; // referenciacion
    cout<<"j se encuentra en: "<<k<<endl;
    // de-referenciacion
    cout<<"5j ="<<5*(*k)<<endl;
    // Algo para enredar la cabeza
    cout<<"?? que hay a dos espacios al lado derecho de j? ="<<*(k+2)<<endl;
    cout<<"?? que hay al lado izquierdo de j? ="<<*(k-1)<<endl;
    cout<<"porque hablamos de apuntadores? z1 y z2 son apuntadores"<<endl;
    cout<<"quien es z1? "<<z1<<endl;
    cout<<"quien es z2? "<<z2<<endl;
    cout<<"que hay en z1[0] = "<<*z1<<endl;
    cout<<"que hay en z1[3] = "<<*(z1+3)<<endl;
    cout<<"que hay en z1[10] = "<<*(z1+10)<<endl;
    cout<<"que hay en z1[11] = "<<*(z1+11)<<endl;
    cout<<"que hay en z1[12] = "<<*(z1+12)<<endl;
    cout<<"que hay en z1[13] = "<<*(z1+13)<<endl;
    cout<<"que hay en z1[14] = "<<*(z1+14)<<endl;
    cout<<"que hay en z1[15] = "<<*(z1+15)<<endl;
    
    // vamos a interactuar con el usuario:
    cout<<"escriba un numero para la creacion del vector ";cin>>j;
    // como hago para asignar un vector de manera dinamica?
    // 1. crear un apuntador
    float *z;
    // 2. crear la memoria y asignarle la referencia al apuntador z
    z = new  float(j); // esto lo crea en el HEAP
    cout<<"la referencia de z es: "<<z<<endl;
    cout<<"que hay en z[0]? "<<z[0]<<endl;
    // 3. al final debemos destruir la memoria
    delete z; z = NULL;
    cout<<"la referencia de z es: "<<z<<endl;
    cout<<"que hay en z[0]? "<<z[0]<<endl;
    return 0;
}