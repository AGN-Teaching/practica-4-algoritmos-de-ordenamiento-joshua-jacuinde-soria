
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>

#include "ordenamiento_conjunto.h"

using namespace std;
using namespace std::chrono;


duration<double> crear_arreglo(int *A, int TAM_ARREGLO, int RANGO_MAX) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    for (int i = 0; i < TAM_ARREGLO; i++) {
        int x = rand() % RANGO_MAX;
        A[i] = x;
    }
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


duration<double> ordenar_merge_sort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    merge_sort(A, 0, TAM_ARREGLO-1);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


duration<double> ordenar_quicksort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    quicksort(A, 0, TAM_ARREGLO-1);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}

duration<double> ordenar_insertion_sort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    insertion_sort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


duration<double> ordenar_selection_sort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    selection_sort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


duration<double> ordenar_bubblesort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    bubblesort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}

int* copiar_arreglo(int A[], int n) {
    int *aux = new int[n];
    for (int i = 0; i < n; i++) {
        aux[i] = A[i];
    }
    return aux;
}


void mostrar_arreglo(int *A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}


void experimentos(int tam, int reps, bool ms, bool qs, bool is, bool ss, bool bs) {
    int TAM_ARREGLO = tam;
    int RANGO_MAX = 10 * TAM_ARREGLO;
    int REPETICIONES = reps;

    srand(static_cast<unsigned>(time(0)));

    ofstream archivo_salida("resultados.txt");  // Abre el archivo de salida

    if (!archivo_salida.is_open()) {
        cerr << "Error al abrir el archivo de salida." << endl;
        return;
    }

    if (ms || qs) {
        double t_prom_ms = 0.0;
        double t_prom_qs = 0.0;

        for (int i = 0; i < REPETICIONES; i++) {
            int *A = new int[TAM_ARREGLO];

            // Arreglo aleatorio
            duration<double> tiempo = crear_arreglo(A, TAM_ARREGLO, RANGO_MAX);

            if (ms) {
                int *aux = copiar_arreglo(A, TAM_ARREGLO);
                tiempo = ordenar_merge_sort(aux, TAM_ARREGLO);
                t_prom_ms += tiempo.count();
                delete[] aux;
            }

            if (qs) {
                int *aux = copiar_arreglo(A, TAM_ARREGLO);
                tiempo = ordenar_quicksort(aux, TAM_ARREGLO);
                t_prom_qs += tiempo.count();
                delete[] aux;
            }

            delete[] A;
        }

        t_prom_ms /= REPETICIONES;
        t_prom_qs /= REPETICIONES;

        archivo_salida << "*** TIEMPO PROMEDIO ***" << endl;
        if (ms) {
            archivo_salida << "Merge sort:\t" << t_prom_ms << "s" << endl;
        }
        if (qs) {
            archivo_salida << "Quicksort:\t" << t_prom_qs << "s" << endl;
        }
    }

    if (is || ss || bs) {
        double t_prom_is = 0.0;
        double t_prom_ss = 0.0;
        double t_prom_bs = 0.0;

        for (int i = 0; i < REPETICIONES; i++) {
            int *A = new int[TAM_ARREGLO];

            // Arreglo aleatorio
            duration<double> tiempo = crear_arreglo(A, TAM_ARREGLO, RANGO_MAX);

            if (is) {
                int *aux = copiar_arreglo(A, TAM_ARREGLO);
                tiempo = ordenar_insertion_sort(aux, TAM_ARREGLO);
                t_prom_is += tiempo.count();
                delete[] aux;
            }

            if (ss) {
                int *aux = copiar_arreglo(A, TAM_ARREGLO);
                tiempo = ordenar_selection_sort(aux, TAM_ARREGLO);
                t_prom_ss += tiempo.count();
                delete[] aux;
            }

            if (bs) {
                int *aux = copiar_arreglo(A, TAM_ARREGLO);
                tiempo = ordenar_bubblesort(aux, TAM_ARREGLO);
                t_prom_bs += tiempo.count();
                delete[] aux;
            }

            delete[] A;
        }

        t_prom_is /= REPETICIONES;
        t_prom_ss /= REPETICIONES;
        t_prom_bs /= REPETICIONES;

        archivo_salida << "*** TIEMPO PROMEDIO ***" << endl;
        if (is) {
            archivo_salida << "Insertion sort:\t" << t_prom_is << "s" << endl;
        }
        if (ss) {
            archivo_salida << "Selection sort:\t" << t_prom_ss << "s" << endl;
        }
        if (bs) {
            archivo_salida << "Bubblesort:\t" << t_prom_bs << "s" << endl;
        }
    }

    archivo_salida.close();  // Cierra el archivo de salida
}



bool incluirAlgoritmo(string listaAlgs, char alg) {
    size_t incluir = listaAlgs.find(alg);
    return incluir != string::npos;
}


int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "Sintaxis: ordenamiento_t <tamaño_arreglo> <repeticiones> <lista_algoritmos>" << endl;
        cout << "Algoritmos:" << endl;
        cout << "m: merge sort" << endl;
        cout << "q: quicksort" << endl;
        cout << "i: insertion sort" << endl;
        cout << "s: selection sort" << endl;
        cout << "b: bubblesort" << endl;
        return EXIT_FAILURE;
    }

    int tam = atoi(argv[1]);
    int reps = atoi(argv[2]);
    string lista_algoritmos = argv[3];

    bool ms = incluirAlgoritmo(lista_algoritmos, 'm');
    bool qs = incluirAlgoritmo(lista_algoritmos, 'q');
    bool is = incluirAlgoritmo(lista_algoritmos, 'i');
    bool ss = incluirAlgoritmo(lista_algoritmos, 's');
    bool bs = incluirAlgoritmo(lista_algoritmos, 'b');

    experimentos(tam, reps, ms, qs, is, ss, bs);

    return EXIT_SUCCESS;
}

