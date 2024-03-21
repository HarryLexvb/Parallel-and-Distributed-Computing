#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>

const int sizes[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000};
const int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

void initialize(double **A, double x[], double y[], int size) {
    for (int i = 0; i < size; i++) {
        x[i] = 1.0;
        y[i] = 0.0;
        A[i] = new double[size];
        for (int j = 0; j < size; j++)
            A[i][j] = 1.0;
    }
}

void loop1(double **A, double x[], double y[], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            y[i] += A[i][j] * x[j];
}

void loop2(double **A, double x[], double y[], int size) {
    for (int j = 0; j < size; j++)
        for (int i = 0; i < size; i++)
            y[i] += A[i][j] * x[j];
}

void deleteArrays(double **A, int size) {
    for (int i = 0; i < size; i++)
        delete[] A[i];
    delete[] A;
}

int main() {
    std::ofstream outputFile(R"(C:\Users\harry\Documentos\Clion Pojects\test2\tiempos.txt)");

    for (int i = 0; i < num_sizes; ++i) {
        int size = sizes[i];
        double **A = new double*[size];
        double *x = new double[size];
        double *y = new double[size];

        initialize(A, x, y, size);

        auto start1 = std::chrono::high_resolution_clock::now();
        loop1(A, x, y, size);
        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed1 = end1 - start1;

        initialize(A, x, y, size); // Reset

        auto start2 = std::chrono::high_resolution_clock::now();
        loop2(A, x, y, size);
        auto end2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed2 = end2 - start2;

        outputFile << "Size: " << size << std::endl;
        outputFile << "Time for loop 1: " << elapsed1.count() << " s\n";
        outputFile << "Time for loop 2: " << elapsed2.count() << " s\n";

        if (elapsed1.count() < elapsed2.count()) outputFile << "The loop 1 is the winner\n";
        else if (elapsed1.count() > elapsed2.count()) outputFile << "The loop 2 is the winner\n";
        else outputFile << "Same time\n";

        outputFile << std::endl;

        deleteArrays(A, size);
        delete[] x;
        delete[] y;
    }

    outputFile.close();

    return 0;
}
