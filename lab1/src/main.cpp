#include <iostream>
#include <chrono>

const int max = 10000;
double A[max][max], x[max], y[max];

void initialize() {
    for (int i = 0; i < max; i++) {
        x[i] = 1.0;
        y[i] = 0.0;
        for (int j = 0; j < max; j++)
            A[i][j] = 1.0;
    }
}

void loop1() {
    for (int i = 0; i < max; i++)
        for (int j = 0; j < max; j++)
            y[i] += A[i][j] * x[j];
}

void loop2() {
    for (int j = 0; j < max; j++)
        for (int i = 0; i < max; i++)
            y[i] += A[i][j] * x[j];
}

int main() {
    initialize();

    auto start1 = std::chrono::high_resolution_clock::now();
    loop1();
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = end1 - start1;

    initialize(); // Reset

    auto start2 = std::chrono::high_resolution_clock::now();
    loop2();
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end2 - start2;

    std::cout << "Time for loop 1: " << elapsed1.count() << " s\n";
    std::cout << "Time for loop 2: " << elapsed2.count() << " s\n";

    if (elapsed1.count() < elapsed2.count()) std::cout << "The loop 1 is the winner\n";
    else if (elapsed1.count() > elapsed2.count()) std::cout << "The second loop is the winner\n";
    else std::cout << "Same time\n";
}
