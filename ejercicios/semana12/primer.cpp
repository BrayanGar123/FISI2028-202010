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
    // Operadores:
    //   aritmeticos: +, -, *, /, %
    //   logicos: && (and), || (or), ! (negacion), ==
    // Precedencia: 1+2*3/6 parentesis! ()
    // Asignacion: =, +=, -=, *=, /= y %=
    i = 3;
    cout<<"variable i="<<i<<endl; // 3
    i = (int) 3.4; // Correcta
    cout<<"variable i="<<i<<endl; // 3
    i += 3; // ==> i = i + 3 
    cout<<"variable i="<<i<<endl; // 6

    i = 8;
    // condicionales (if, else) y loops (for y while)
    if(i == 6){
        cout<<"variable i="<<i<<endl; // 6
    }
    else if(i == 8){
        cout<<"la variable no es correcta pero podria serlo"<<endl;
    }
    else{
        cout<<"la variable no es correcta"<<endl;
    }
    
    // 1. funciones
    // 2. Arreglos y "apuntadores": strings (C,C++)
    // 3. Archivos de datos
    return 0; // Exit code
}
