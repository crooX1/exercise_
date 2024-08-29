#include <stdio.h>
#include <math.h>
#include <windows.h>

int main() {
    // Русский язык
    SetConsoleOutputCP(CP_UTF8);
    double a, b, c, discriminant, root1, root2, realPart, imagPart;

    // Запрос коэффициентов у пользователя
    printf("Введите коэффициенты a, b и c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    discriminant = b * b - 4 * a * c;

    // Проверка дискриминанта
    if (discriminant > 0) {
        // Корни реальные и разные
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Корни уравнения: root1 = %.2lf и root2 = %.2lf\n", root1, root2);
    } else if (discriminant == 0) {
        // Корни реальные и одинаковые
        root1 = root2 = -b / (2 * a);
        printf("Корни уравнения: root1 = root2 = %.2lf\n", root1);
    } else {
        // Корни комплексные и разные
        realPart = -b / (2 * a);
        imagPart = sqrt(-discriminant) / (2 * a);
        printf("Корни уравнения: root1 = %.2lf+%.2lfi и root2 = %.2lf-%.2lfi\n", realPart, imagPart, realPart, imagPart);
    }

    // Проверка погрешности вычислений
    printf("Проверка первого корня: %.2lf\n", a * root1 * root1 + b * root1 + c);
    printf("Проверка второго корня: %.2lf\n", a * root2 * root2 + b * root2 + c);

    return 0;
}