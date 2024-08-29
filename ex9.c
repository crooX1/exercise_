#include <stdio.h>
#include <windows.h>
// Функция для решения системы уравнений методом обратной подстановки
void solve_upper_triangular(int n, double *A, double *B, double *X) {
    for (int i = n - 1; i >= 0; i--) {
        X[i] = B[i];
        for (int j = i + 1; j < n; j++) {
            X[i] -= A[i * n + j] * X[j];
        }
        X[i] /= A[i * n + i];
    }
}

int main() {
    // Русский язык
    SetConsoleOutputCP(CP_UTF8);

    int n;
    printf("Введите размерность n матрицы A: \n");
    scanf("%d", &n);

    double A[n * n]; // Одномерный массив для хранения элементов матрицы A
    double B[n];     // Массив для хранения вектора B
    double X[n];     // Массив для хранения вектора решения X

    printf("Введите элементы верхнетреугольной матрицы A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            scanf("%lf", &A[i * n + j]);
        }
    }

    printf("Введите элементы вектора B:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &B[i]);
    }

    solve_upper_triangular(n, A, B, X);

    printf("Вектор решения X:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", X[i]);
    }
    printf("\n");

    return 0;
}