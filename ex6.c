#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_SIZE 100

// Функция для проверки максимальной длины последовательности нулей
int check_zeros(int arr[][MAX_SIZE], int k, int m) {
    int max_length = 0, length;

    // Проверка по горизонтали
    for (int i = 0; i < k; i++) {
        length = 0;
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                length++;
                if (length > max_length) max_length = length;
            } else {
                length = 0;
            }
        }
    }

    // Проверка по вертикали
    for (int j = 0; j < m; j++) {
        length = 0;
        for (int i = 0; i < k; i++) {
            if (arr[i][j] == 0) {
                length++;
                if (length > max_length) max_length = length;
            } else {
                length = 0;
            }
        }
    }

    // Проверка по диагоналям
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            length = 0;
            for (int l = 0; l < k && l < m; l++) {
                if (i + l < k && j + l < m && arr[i + l][j + l] == 0) {
                    length++;
                    if (length > max_length) max_length = length;
                } else {
                    break;
                }
            }
        }
    }

    // Проверка по обратным диагоналям
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            length = 0;
            for (int l = 0; l < k && l < m; l++) {
                if (i + l < k && j - l >= 0 && arr[i + l][j - l] == 0) {
                    length++;
                    if (length > max_length) max_length = length;
                } else {
                    break;
                }
            }
        }
    }

    return max_length;
}

int main() {
    // Русский язык
    SetConsoleOutputCP(CP_UTF8);

    int k, m;
    int matrix[MAX_SIZE][MAX_SIZE];

    printf("Введите размеры матрицы k и m: \n");
    scanf("%d %d", &k, &m);

    printf("Введите элементы матрицы L(k,m) из нулей и единиц:\n");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Самая длинная цепочка подряд стоящих нулей: %d\n", check_zeros(matrix, k, m));

    return 0;
}