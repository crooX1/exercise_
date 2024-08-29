#include <stdio.h>
#include <string.h>
#include <windows.h>
#define MAX_DIGITS 50 // Максимальное количество цифр в числе

// Функция для суммирования двух чисел в системе счисления q
void sum_in_base(char num1[], char num2[], char result[], int base) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int carry = 0;
    int i = len1 - 1, j = len2 - 1, k = 0;

    // Обнуляем результат
    memset(result, '0', MAX_DIGITS);
    result[MAX_DIGITS] = '\0';

    // Суммируем числа начиная с младших разрядов
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        carry = sum / base;
        result[k++] = (sum % base) + '0';
    }

    // Переворачиваем результат
    for (int l = 0; l < k / 2; l++) {
        char temp = result[l];
        result[l] = result[k - l - 1];
        result[k - l - 1] = temp;
    }
}

int main() {
    // Русский язык
    SetConsoleOutputCP(CP_UTF8);
    int m, n, q;
    char matrix[MAX_DIGITS][MAX_DIGITS];
    char sum[MAX_DIGITS] = {0};
    char temp_sum[MAX_DIGITS] = {0};

    printf("Введите размеры матрицы K(m,n) и систему счисления q: \n");
    scanf("%d %d %d", &m, &n, &q);

    printf("Введите строки матрицы, представляющие числа:\n");
    for (int i = 0; i < m; i++) {
        scanf("%s", matrix[i]);
    }

    // Суммируем числа
    for (int i = 0; i < m; i++) {
        sum_in_base(sum, matrix[i], temp_sum, q);
        strcpy(sum, temp_sum);
    }

    printf("Сумма чисел в системе счисления %d: %s\n", q, sum);

    return 0;
}