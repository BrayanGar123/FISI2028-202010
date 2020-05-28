/*
    Vamos a construir un vector fila y una matriz
*/

#include <iostream>
#include <fstream>
// Por favor leer esto:
// https://en.cppreference.com/w/c/numeric/tgmath
#include <ctgmath>

using namespace std;

// Unas funciones útiles
void hByte(unsigned int);

int main(void){
    // Más detalles en:
    // http://www.cplusplus.com/reference/fstream/fstream/
    fstream outFile1,outFile2;
    outFile1.open ("resultados_X.txt", ios::out | ios::trunc);
    outFile2.open ("resultados_A.txt", ios::out | ios::trunc);
    /*
        1. Definimos N_x como el número de elementos del vector fila 'x'
        2. Definimos N_A_r como el número de filas de la matriz 'A'
        3. Definimos N_A_c como el número de columnas de la matriz 'A'
    */
    unsigned int N_x = 0;
    unsigned int N_A_r = 0,N_A_c = 0;
    // Definimos los apuntadores para el vector 'x' y la matriz 'A'
    double *X,**A;
    
    cout<<"Por favor ingrese la dimensión de 'X'? ";
    cin>>N_x;
    if(N_x > 1e6)
        cout<<"\tDimensión muy grande, "<<N_x<<"."<<endl;
    cout<<"Por favor ingrese las dimensiones de 'A'? (filas,columnas) ";
    scanf("%d,%d",&N_A_r,&N_A_c);
    if(N_A_r*N_A_c > 1e6)
        cout<<"\tDimensión muy grande, ("<<N_A_r<<" x "<<N_A_c<<")."<<endl;
    // Creamos el espacio para los vectores y matrices con NEW
    try{
        X = new double [N_x];
        // Inicializamos el vector con ceros
        cout<<"(PROC) Inicializando el vector..."<<endl;
        for(unsigned int j=0;j<N_x;j++)
            X[j] = 0;
        hByte(N_x * sizeof(double));
    } catch(bad_alloc& el_error){
        cerr<<"(ERROR) Error creando el vector 'X'"<<endl;
    }
    try{
        // Método: primero crea un vector de apuntadores con
        //         el número de filas (ROW-wise).
        cout<<"Creación de matrices por filas: ROW-wise."<<endl;
        cout<<"\tNOTA: Se puede hacer COL-wise también"<<endl;
        A = new double* [N_A_r];
        // // Method (a): en cada sitio del vector de apuntadores
        // //             crea vectores fila con el número de
        // //             columnas en cada "fila"
        // for(unsigned int j=0;j<N_A_r;j++)
        //    A[j] = new double[N_A_c];
        // Method (b): crea un solo vector con el total de:
        //             filas * columnas...
        A[0] = new double [N_A_r*N_A_c];
        //             luego asigna la referencia de la memoria
        //             del 'inicio' de cada "fila" a cada sitio
        //             del vector de apuntadores
        for(unsigned int j=1;j<N_A_r;j++)
            A[j] = A[0] + N_A_c*j;
        // Inicializamos la matriz con ceros
        cout<<"(PROC) Inicializando la matriz..."<<endl;
        for(unsigned int j=0;j<N_A_r;j++)
            for(unsigned int k=0;k<N_A_c;k++)
                A[j][k] = 0;
        hByte(N_A_r * N_A_c * sizeof(double));
        
    } catch(bad_alloc& el_error){
        cerr<<"(ERROR) Error creando la matriz 'A'"<<endl;
    }
    
    cout<<"(RES) Llenamos la matriz con f(x,y)=sin(5x)cos(2y)"<<endl;
    cout<<"      asumiendo que la 'x' varía según la fila"<<endl;
    cout<<"      y 'y' según la columna"<<endl;
    cout<<"(INIT) 'x' y 'y' están definidos entre [0,1], luego"<<endl;
    cout<<"       dx = 1/(Nrows-1) y dy=1/(Ncols-1)."<<endl;
    double dx=1.0/(N_A_r-1),dy=1.0/(N_A_c-1);
    double x,y;
    for(unsigned int j=0;j<N_A_r;j++)
        for(unsigned int k=0;k<N_A_c;k++){
            x = dx * j;
            y = dy * k;
            A[j][k] = sin(5*x)*cos(2*y);
        }

    cout<<"Guardamos el vector en un archivo: resultados_X.txt"<<endl;
    for(unsigned int j=0;j<N_x;j++)
        outFile1<<X[j]<<endl;
    outFile1.close();
    cout<<"Guardamos la matriz en un archivo: resultados_A.txt"<<endl;
    for(unsigned int j=0;j<N_A_r;j++){
        for(unsigned int k=0;k<N_A_c;k++)
            outFile2<<A[j][k]<<" ";
        // outFile2<<'\b'<<endl;
    }
    outFile2.close();
    cout<<"Abran los archivo con Python y grafiquen con plt.imshow()"<<endl;

    cout<<"(PROC) eliminando memoria dinámica: x"<<endl;
    delete [] X, X=nullptr;
    cout<<"(PROC) eliminando memoria dinámica: A"<<endl;
    // // Method (a): borra cada vector fila antes de borrar el
    // //             vector de apuntadores
    // for(unsigned int j = 0; j < N_A_r; j++)
    //     delete [] A[j];
    // delete [] A;
    // Method (b): borra el vector fila 'completo' (que está)
    //             en [0] y después borra el vector de apuntadores
    delete [] A[0];
    delete [] A, A = nullptr;
    return 0;
}



void hByte(unsigned int bytes){
    char r_array[128] = "0 Bytes";
    if (bytes > 0){
        if (bytes >= 1073741824) snprintf(r_array, sizeof r_array, "%.2f GBytes", (((float) bytes)/1073741824));
        else if (bytes >= 1048576) snprintf(r_array, sizeof r_array, "%.2f MBytes", (((float) bytes)/1048576));
        else if (bytes >= 1024) snprintf(r_array, sizeof r_array, "%.2f KBytes", (((float) bytes)/1024));
        else snprintf(r_array, sizeof r_array, "%d Bytes", bytes);
    }
    printf("(INFO) Tamaño del arreglo = %s\n",r_array);
};
