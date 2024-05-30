#include <iostream>
#include <vector>
#include <thread>
#include <random>  // Para std::random_device y std::mt19937

const int n = 1024;  // Tamaño de las matrices
const int p = 8;     // Número de hilos

// Función que cada hilo ejecutará para sumar las matrices
void sum_matrices(int thread_id, const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C) {
    int rows_per_thread = n / p;
    int start_row = thread_id * rows_per_thread;
    int end_row = (thread_id + 1) * rows_per_thread;

    for (int i = start_row; i < end_row; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main() {
    // Inicialización de matrices A y B con valores aleatorios
    std::vector<std::vector<int>> A(n, std::vector<int>(n));
    std::vector<std::vector<int>> B(n, std::vector<int>(n));
    std::vector<std::vector<int>> C(n, std::vector<int>(n));

    std::random_device rd;  // Generador de números aleatorios
    std::mt19937 gen(rd()); // Motor de generación de números aleatorios
    std::uniform_int_distribution<> dis(0, 99); // Distribución uniform

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = dis(gen);
            B[i][j] = dis(gen);
        }
    }

    // Vector para almacenar los hilos
    std::vector<std::thread> threads;

    // Creación y lanzamiento de hilos
    for (int i = 0; i < p; ++i) {
        threads.emplace_back(sum_matrices, i, std::ref(A), std::ref(B), std::ref(C));
    }

    // Unión de hilos
    for (int i = 0; i < p; ++i) {
        threads[i].join();
    }

    // mostramos una parte de la matriz C
    std::cout << "C[0][0] = " << C[0][0] << std::endl;
    std::cout << "C[n-1][n-1] = " << C[n-1][n-1] << std::endl;

    return 0;
}
