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

int N=10;
void sum(int a,int b=1); // en el scope: global
float div(int a,int b=1);

// la funcion main que es la funcion que se ejecuta en el t=0
// esta funcion SIEMPRE tiene que devolver un numero entero
// la convencion es que el numero entero que retorna depende de si
// la funcion se ejecuto correctamente
int main(){
    // declaro la variable
    // pero NO esta inicializada
    int i=0,j=0; float x,y=0; // en el scope: main
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
    
    // void sum(int a, int b=1) = a+b
    sum(1,2);
    sum(5); // 5+1
    
    x = div(3,2);
    cout<<"el valor de la division es: "<<x<<endl;
    // 1. funciones
    // 2. scoping {}
    if(i == 1){
        int k = 3;
        cout<<k<<endl;
    } else {
        int l = 4;
        cout<<l<<endl;
    }
    int k;
    // 3. arreglos y "apuntadores": strings (C,C++)
    // 4. archivos de datos
    return 0; // Exit code
}


// <tipo de variable return> "nombre funcion"(parametros){}
void sum(int a, int b){
    cout<<"la variable global N es "<<N<<endl;
    N++; // N=N+1
    cout<<"la suma es: "<<a+b<<endl;
}

float div(int a, int b){
    cout<<"la variable global N es "<<N<<endl;
    return (float) a/b;
}
