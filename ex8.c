#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Функция для вычисления площади многоугольника
double polygon_area(int (*coords)[2], int n) {
    double area = 0.0;
    int j = n - 1;

    for (int i = 0; i < n; i++) {
        area += (coords[j][0] + coords[i][0]) * (coords[j][1] - coords[i][1]);
        j = i;  // j - предыдущая вершина
    }

    return abs(area / 2.0);
}

int main() {
    // Русский язык
    SetConsoleOutputCP(CP_UTF8);
    int n;
    printf("Введите количество вершин многоугольника: \n");
    scanf("%d", &n);

    int coords[n][2]; // Массив для хранения координат вершин

    printf("Введите координаты вершин (x y) в порядке обхода:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coords[i][0], &coords[i][1]);
    }

    double area = polygon_area(coords, n);
    printf("Площадь многоугольника: %.2f\n", area);

    return 0;
}