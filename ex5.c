#include <stdio.h>
#include <windows.h>
int josephus(int n, int m) {
    if (n == 1)
        return 1;
    else
        // Смещение позиции после каждой "казни"
        return (josephus(n - 1, m) + m - 1) % n + 1;
}

int main() {
    // Русский язык
    SetConsoleOutputCP(CP_UTF8);

    int n, m;
    printf("Введите общее количество человек (n): \n");
    scanf("%d", &n);

    // Находим номер последнего оставшегося человека для разных m
    for (m = 2; m <= n; m++) {
        if (josephus(n, m) == 1) {
            printf("Чтобы первый человек остался 'в живых', m должно быть: %d\n", m);
            break;
        }
    }

    // Если m не найдено в пределах от 2 до n, сообщаем об этом
    if (m == n + 1) {
        printf("Не найдено такое m > 1, при котором первый человек останется 'в живых'.\n");
    } else {
        printf("Последний оставшийся человек под номером: %d\n", josephus(n, m));
    }

    return 0;
}