/*
    Vamos a resolver un problema de difusión unidimensional

    Instrucciones de compilación:

    g++ -std=c++11 difusion.cpp

    Instrucciones de ejecución:
    ./a.out
*/

#include <iostream>
#include <fstream>
#include <ctgmath>

using namespace std;

int main(void){
    fstream outFile;
    unsigned int N=0;
    unsigned int Nt=0;
    double L=0,l=0;
    double T=10;
    double dx=0,dt=0;
    // Es conveniente tener las variables 'x' y 't'
    double x=0,t=0;
    // Definimos los apuntadores para el vector 'U'
    double *U;

    // 1. Cree el archivo difusion.txt
    outFile.open ("difusion.txt", ios::out | ios::trunc);

    // 2. Utilice 'cin' para que el usuario tenga que digitar N, Nt, L y l

    // 3. Ya con N y Nt defina dx y dt a saber que el tiempo máximo es T=10
    //    como está definido en la línea 17. Nota: Usted puede cambiar el
    //    tiempo si bien lo desea.

    // 4. Ya con N, cree el vector U de manera dinámica usando 'new'

    // 5. Llene el vector U con las condiciones iniciales de U(x,0)

    // 6. Guarde el vector U(x,0) en la primera línea del archivo
    //    difusion.txt utilizando un for loop, la notación conveniente
    //    outFile<<... Recuerden el "endl" sólo al final del arreglo.
    //    la idea es que la primera linea del archivo sea:
    //    0 0 0 ... 0 0 1/dt 0 0 ... 0 0 0

    // 7. Utilice un for loop (bucle) para actualizar el tiempo y así actua-
    //    lizar U(x,t) con las reglas descritas en el texto. Fíjense que ya
    //    cuentan con U(x,0) luego de la primera iteración encontrarían
    //    U(x,dt). Al finalizar la actualización en cada iteración no olvide
    //    guardar el vector U(x,t) en una fila del archivo difusion.txt.
    for(int j=0;j<Nt;j++){
        cout<<" cada iteración..."<<endl;
    }

    // 8. Por último destruya el vector U y cierre el archivo difusion.txt
    delete [] U; U = nullptr;
    outFile.close();
    return 0;
}
