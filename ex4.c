#include <stdio.h>
#include <windows.h>
void adjustMatrix(int rows, int cols, float matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        float sum = 0;
        // Считаем сумму элементов в строке
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        // Вычисляем среднее арифметическое
        float average = sum / cols;

        // Вычитаем среднее из каждого элемента строки
        for (int j = 0; j < cols; j++) {
            matrix[i][j] -= average;
        }
    }
}

int main() {
    // Русский язык
    SetConsoleOutputCP(CP_UTF8);

    int l, m;
    printf("Введите количество строк матрицы: \n");
    scanf("%d", &l);
    printf("Введите количество столбцов матрицы: \n");
    scanf("%d", &m);

    float matrix[l][m];

    // Заполнение матрицы
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Корректировка матрицы
    adjustMatrix(l, m, matrix);

    // Вывод результата
    printf("Измененная матрица:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}