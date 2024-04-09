#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para generar una matriz aleatoria de tamaño nxn
void generarMatriz(int** &matriz, int n) {
    matriz = new int*[n];
    for (int i = 0; i < n; ++i) {
        matriz[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = rand() % 50; // Valores entre 0 y 49
        }
    }
}

void generarMatrizPlana(int* matriz, int n){
    for (int i = 0; i < n*n; ++i) {
        matriz[i] = rand() % 50; // Vamalores entre 0 y 49
    }
}

// Función para inicializar una matriz con ceros
void inicializarMatrizConCeros(int** &matriz, int n) {
    matriz = new int*[n]; // Asigna memoria para las filas
    for (int i = 0; i < n; ++i) {
        matriz[i] = new int[n]; // Asigna memoria para las columnas
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = 0; // Inicializa cada elemento con 0
        }
    }
}

// Función para imprimir una matriz de tamaño nxn
void imprimirMatriz(int** matriz, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void imprimirMatrizPlana(int *matriz, int n) {
    for (int i = 0; i < n*n; ++i) {
        cout << matriz[i] << " ";
        if((i + 1) % n == 0){ // Cambiado de i % n == 0 a (i + 1) % n == 0
            cout << endl;
        }
    }
}

// Función para sumar dos matrices de tamaño nxn
void sumarMatrices(int** matrizA, int** matrizB, int** matrizSuma, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrizSuma[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}

// Función para restar dos matrices de tamaño nxn
void restarMatrices(int** matrizA, int** matrizB, int** matrizResta, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrizResta[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }
}

// Función para liberar la memoria ocupada por una matriz
void liberarMatriz(int** matriz, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

// Función para sumar una matriz plana con una matriz normal de tamaño nxn
void sumarMatrizPlanaConNormal(int* matrizPlana, int** matrizNormal, int n) {
    // Sumar cada elemento de la matriz plana con el elemento correspondiente de la matriz normal
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrizNormal[i][j] += matrizPlana[i * n + j];
        }
    }
}

int main(int argc, char *argv[]) {
    // Verificar que se proporcionen suficientes argumentos
    if (argc != 3) {
        cout << "Ejecutar como ./main <n> <seed>" << endl;
        return 1;
    }

    int n = atoi(argv[1]); // Tamaño de la matriz
    int seed = atoi(argv[2]);
    srand(seed); // Semilla para la generación de números aleatorios

    int** matrizA;
    int** matrizB;
    int** matrizSuma;
    int** matrizResta;
    int* matrizPlana = new int[n*n];

    generarMatriz(matrizA, n);
    generarMatriz(matrizB, n);
    generarMatrizPlana(matrizPlana, n);

    inicializarMatrizConCeros(matrizSuma, n);
    inicializarMatrizConCeros(matrizResta, n);

    printf("Matriz A:\n");
    imprimirMatriz(matrizA, n);

    printf("\nMatriz B:\n");
    imprimirMatriz(matrizB, n);

    sumarMatrices(matrizA, matrizB, matrizSuma, n);
    printf("\nMatriz Suma (A + B):\n");
    imprimirMatriz(matrizSuma, n);

    restarMatrices(matrizA, matrizB, matrizResta, n);
    printf("\nMatriz Resta (A - B):\n");
    imprimirMatriz(matrizResta, n);

    printf("\nMatriz PLANA:\n");
    imprimirMatrizPlana(matrizPlana, n);

    sumarMatrizPlanaConNormal(matrizPlana, matrizA, n);
    printf("\nMatriz A (A + Plana):\n");
    imprimirMatriz(matrizA, n);

    liberarMatriz(matrizA, n);
    liberarMatriz(matrizB, n);
    liberarMatriz(matrizSuma, n);
    liberarMatriz(matrizResta, n);
    delete[] matrizPlana;

    return 0;
}
