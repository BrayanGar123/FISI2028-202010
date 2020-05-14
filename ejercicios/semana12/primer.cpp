/* 

Encabezado:
0. instrucciones de licenciamiento
1. librerias: #include <....>, #include ""

2. definiciones: #define var valor
3. declaraciones de funciones


*/

#include <iostream>
// el namespace de la libreria estandar: std
using namespace std;



// la funcion main que es la funcion que se ejecuta en el t=0
int main(){
    // declaro la variable
    // pero NO esta inicializada
    int i=0,j=0; float x,y=0;
    /*
        
        Cada compilador inicializa las variables de una
        manera especifica: g++ (gnu) solo
        asigna el espacio en memoria.
    
    */
    // python: print("hola mundo")
    // c++:
    cout<<"variable i="<<i<<endl;
    cout<<i<<" + "<<j<<" = "<<i+j<<endl;
    // Asignacion de la variable
    i = 3;
    return 0;
}
