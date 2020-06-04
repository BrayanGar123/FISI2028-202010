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
    // Número de divisiones para la barra
    unsigned int N=0;
    // Número de pasos de tiempo totales
    unsigned int Nt=0;
    // Dimensiones de la barra y de l
    double L=0,l=0;
    // Adiciono el parámetro de difusión por conveniencia
    double D=0.5;
    // El tiempo total de la "simulación"
    double T=10;
    // Tamaño de la grilla y paso de tiempo
    double dx=0,dt=0;
    // Es conveniente tener las variables 'x' y 't'
    double x=0,t=0;
    // Definimos los apuntadores para el vector 'U'
    double *U;

    // 1. Cree el archivo difusion.txt
    outFile.open ("difusion.txt", ios::out | ios::trunc);

    // 2. Utilice 'cin' para que el usuario tenga que digitar N, Nt, L y l
    cout<<"Ingrese los siguientes valores:"<<endl;
    while(L<=0){ cout<<"\tL=? ";cin>>L; }
    while(l<=0 || l> L/2){ cout<<"\tl=? [0<l<L/2] ";cin>>l; }
    while(N==0) { cout<<"\tN=? [entero >0] ";cin>>N; }
    while(Nt==0){ cout<<"\tNt=? [entero >0] ";cin>>Nt; }

    // 3. Ya con N y Nt defina dx y dt a saber que el tiempo máximo es T=10
    //    como está definido en la línea 17. Nota: Usted puede cambiar el
    //    tiempo si bien lo desea.
    dx = L/N;
    dt = T/Nt;
    cout<<"(INFO) 2D(dt/dx^2)="<<2*D*dt/(dx*dx)<<" ?<1"<<endl;
    if(2*D*dt/(dx*dx)>=1)
        cout<<"(WARN) Cuidado, la discretización no es adecuada"<<endl;
    // Necesito una variable que me diga la posición l donde estará
    // la concentración inicial
    unsigned int Nl = round((l/L)*N);
    cout<<"(INFO) Nl="<<Nl<<endl;

    // 4. Ya con N, cree el vector U de manera dinámica usando 'new'
    U = new double [N+1]; // Recordemos que para N intervalos hay N+1 puntos

    // 5. Llene el vector U con las condiciones iniciales de U(x,0)
    for(int j = 0; j <= N; j++)
        if(j == Nl)
            U[j] = 1/dx;
        else
            U[j] = 0;

    // 6. Guarde el vector U(x,0) en la primera línea del archivo
    //    difusion.txt utilizando un for loop, la notación conveniente
    //    outFile<<... Recuerden el "endl" sólo al final del arreglo.
    //    la idea es que la primera linea del archivo sea:
    //    0 0 0 ... 0 0 1/dt 0 0 ... 0 0 0
    for(int j = 0; j <= N; j++)
        if(j < N)
            outFile<<U[j]<<" ";
        else
            outFile<<U[j]<<endl;

    // 7. Utilice un for loop (bucle) para actualizar el tiempo y así actua-
    //    lizar U(x,t) con las reglas descritas en el texto. Fíjense que ya
    //    cuentan con U(x,0) luego de la primera iteración encontrarían
    //    U(x,dt). Al finalizar la actualización en cada iteración no olvide
    //    guardar el vector U(x,t) en una fila del archivo difusion.txt.
    /*
        Como estoy actualizando todo el vector U, pero este depende de un
        estado anterior y los vecinos a un sitio, debo guardar una variable
        de uno de los vecinos para poder actualizar todos los elementos
        sin inconsistencias. Voy a hacer el barrido de izquierda a derecha,
        luego siempre tengo que guardar el estado del anterior. El primero y
        último son cero siempre, entonces sólo actualizao del 1 hasta el N-1
    */
    double U_prev = 0;
    double U_new = 0;
    for(int j=0;j<Nt;j++){
        U_prev = U[0]; // Inicializamos el "previo"
        for(int k=1;k<N;k++){
            U_new = U[k] + (dt*D/(dx*dx))*(U[k+1]-2*U[k]+U_prev);
            U_prev = U[k];
            U[k] = U_new;
        }
        // Ahora guardo el nuevo estado en el archivo de resultados
        for(int j = 0; j <= N; j++)
            if(j < N)
                outFile<<U[j]<<" ";
            else
                outFile<<U[j]<<endl;
    }

    // 8. Por último destruya el vector U y cierre el archivo difusion.txt
    delete [] U; U = nullptr;
    outFile.close();
    return 0;
}
