#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_PEOPLE 100

// Структура для хранения полного имени
typedef struct {
    char surname[MAX_NAME_LENGTH];
    char name[MAX_NAME_LENGTH];
    char patronymic[MAX_NAME_LENGTH];
} FullName;

// Функция для сравнения двух имен
int compare_names(const void *a, const void *b) {
    FullName *name1 = (FullName *)a;
    FullName *name2 = (FullName *)b;

    int res = strcmp(name1->surname, name2->surname);
    if (res == 0) {
        res = strcmp(name1->name, name2->name);
        if (res == 0) {
            res = strcmp(name1->patronymic, name2->patronymic);
        }
    }
    return res;
}

// Функция для коррекции регистра букв в именах
void correct_case(char *str) {
    if (str[0] != '\0') {
        str[0] = toupper((unsigned char)str[0]);
        for (int i = 1; str[i] != '\0'; i++) {
            str[i] = tolower((unsigned char)str[i]);
        }
    }
}

// Функция для исправления регистра во всех частях имени
void correct_full_name(FullName *name) {
    correct_case(name->surname);
    correct_case(name->name);
    correct_case(name->patronymic);
}

int main() {
    FullName people[MAX_PEOPLE];
    int n;

    printf("Введите количество людей: ");
    scanf("%d", &n);
    getchar(); // Удаление символа новой строки после числа

    printf("Введите фамилии, имена и отчества (каждое с новой строки):\n");
    for (int i = 0; i < n; i++) {
        printf("Человек %d:\n", i + 1);
        printf("Фамилия: ");
        fgets(people[i].surname, MAX_NAME_LENGTH, stdin);
        printf("Имя: ");
        fgets(people[i].name, MAX_NAME_LENGTH, stdin);
        printf("Отчество: ");
        fgets(people[i].patronymic, MAX_NAME_LENGTH, stdin);

        // Удаление символа новой строки
        people[i].surname[strcspn(people[i].surname, "\n")] = 0;
        people[i].name[strcspn(people[i].name, "\n")] = 0;
        people[i].patronymic[strcspn(people[i].patronymic, "\n")] = 0;

        // Коррекция регистра
        correct_full_name(&people[i]);
    }

    // Сортировка списка имен
    qsort(people, n, sizeof(FullName), compare_names);

    printf("Отсортированный список:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %s %s\n", people[i].surname, people[i].name, people[i].patronymic);
    }

    return 0;
}