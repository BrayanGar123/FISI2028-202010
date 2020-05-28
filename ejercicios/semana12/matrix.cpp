/*
    Vamos a construir un vector fila y una matriz
*/

#include <iostream>
#include <fstream> // escribir y leer archivos
#include <ctgmath>

using namespace std;

// Unas funciones útiles
void hByte(unsigned int);

int main(void){
    
    fstream outFile1,outFile2;
    outFile1.open("resultados_X.txt",ios::out | ios::trunc);
    outFile2.open("resultados_A.txt",ios::out | ios::trunc);
    
    unsigned int N_x=0; // este es el # de sitios del vector
    unsigned int N_A_r=0,N_A_c=0; // # de filas y # de columnas
    // Definir los apuntadores para crear el vector
    // y la matriz
    double *X,**A;
    
    cout<<"Escriba la dimensión de 'X'? ";cin>>N_x;
    cout<<"El vector ocupará: ";
    hByte(N_x*sizeof(double));
    if(N_x > 1e8){
        cout<<"(WARN) OJO, la dimensión es muy grande..."<<endl;
        // exit(2);
    }
    cout<<"Escriba (filas,columnas) de la matriz 'A'? ";scanf("%d,%d",&N_A_r,&N_A_c);
    cout<<"La matriz ocupará: ";
    hByte(N_A_r*N_A_c*sizeof(double)+N_A_r*sizeof(double*));

    if(N_A_r*N_A_c > 1e8)
        cout<<"(WARN) OJO, la dimensión de la matriz es muy grande..."<<endl;

    try{
        X = new double [N_x];
        for(int j=0;j<N_x;j++)
            X[j] = 0;
    } catch(bad_alloc &el_error){
        cerr<<"(ERR) Error creando el vector 'X'"<<endl;
        exit(1);
    }

    // **A significa que estamos creando un apuntador A que es la referencia
    // a una dirección de memoria que contiene la información de otra dirección
    // de memoria
    try{
        A = new double*[N_A_r];
        // $%^@#$ -> 0: direccion de memoria para el vector fila 0
        // $%^@#$+1 -> 1: direccion de memoria para el vector fila 1
        // $%^@#$+2 -> 2: direccion de memoria para el vector fila 2
        // etc
        A[0] = new double [N_A_r*N_A_c]; // Garantizo que la memoria sea no-fragmetada
        for(int j=1;j<N_A_r;j++)
            A[j] = A[0]+N_A_c*j;
        for(int j=0;j<N_A_r;j++)
            for(int k=0;k<N_A_c;k++)
                A[j][k] = 0;
    } catch(bad_alloc &el_error){
        cerr<<"(ERR) Error creando la matria 'A'"<<endl;
        exit(1);
    }
    
    // queremos escribir una función f(x,y) en forma discreta
    // f(x,y) = sin(5x)cos(2y)
    // 'x' y 'y' están entre [0,1]
    // x -> primer indice
    // y -> segundo indice
    // dx = (1-0)/(N_A_r-1)
    // dy = (1-0)/(N_A_c-1)
    // A[j][k] = f(0+j*dx,0+k*dy)
    double dx=1.0/(N_A_r-1),dy=1.0/(N_A_c-1);
    double x,y;
    for(int j=0;j<N_A_r;j++)
        for(int k=0;k<N_A_c;k++){
            x = j*dx;
            y = k*dy;
            A[j][k] = sin(5*x)*cos(2*y);
        }

    for(int j=0;j<N_x;j++)
        outFile1<<X[j]<<endl;
    for(int j=0;j<N_A_r;j++){
        for(int k=0;k<N_A_c;k++)
            outFile2<<A[j][k]<<' ';
        outFile2<<endl;
    }
    // Limpieza de memoria
    outFile1.close();
    outFile2.close();
    delete [] X; X = nullptr;
    delete [] A[0];
    delete [] A; A = nullptr;
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
