include <stdio.h>
#include <stdbool.h>
#include <windows.h>

bool canPlaceHouses(int a, int b, int p, int q, int r, int s) {
    // Проверяем, можно ли разместить дома вдоль одной стороны
    if ((p + r <= a && q <= b && s <= b) || (p + r <= b && q <= a && s <= a)) {
        return true;
    }
    // Проверяем, можно ли разместить дома вдоль разных сторон
    if ((p <= a && q + s <= b && r <= a) || (p <= b && q + s <= a && r <= b)) {
        return true;
    }
    // Проверяем, можно ли разместить дома вдоль разных сторон (с переворотом)
    if ((q <= a && p + s <= b && r <= a) || (q <= b && p + s <= a && r <= b)) {
        return true;
    }
    // Если ни один из способов не подходит, возвращаем false
    return false;
}

int main() {
    // Русский язык
    SetConsoleOutputCP(CP_UTF8);

    int a, b, p, q, r, s;

    // Запрос размеров участка и домов у пользователя
    printf("Введите размеры участка (a и b): \n");
    scanf("%d %d", &a, &b);
    printf("Введите размеры первого дома (p и q): \n");
    scanf("%d %d", &p, &q);
    printf("Введите размеры второго дома (r и s): \n");
    scanf("%d %d", &r, &s);

    // Вызов функции и вывод результата
    if (canPlaceHouses(a, b, p, q, r, s)) {
        printf("Два дома можно разместить на участке.\n");
    } else {
        printf("Два дома нельзя разместить на участке.\n");
    }

    return 0;
}