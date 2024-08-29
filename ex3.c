#include <stdio.h>
#include <windows.h>

void printSchedule(int startHour, int startMinute, int endHour, int endMinute, int routeDuration, int restTime) {
    int currentTime = startHour * 60 + startMinute; // Переводим время начала в минуты
    int endTime = endHour * 60 + endMinute; // Переводим время окончания в минуты

    // Печатаем расписание, пока текущее время не превысит время окончания
    while (currentTime <= endTime) {
        int hour = currentTime / 60;
        int minute = currentTime % 60;
        printf("%02d:%02d\n", hour, minute); // Выводим время отправления

        // Добавляем время маршрута и отдыха для следующего цикла
        currentTime += routeDuration + restTime;
    }
}

int main() {
    // Русский язык
    SetConsoleOutputCP(CP_UTF8);

    int startHour, startMinute, endHour, endMinute, routeDuration, restTime;

    // Запрос данных у пользователя
    printf("Введите время начала работы маршрута (час и минуты): \n");
    scanf("%d %d", &startHour, &startMinute);
    printf("Введите время окончания работы маршрута (час и минуты): \n");
    scanf("%d %d", &endHour, &endMinute);
    printf("Введите протяженность маршрута в минутах (в один конец): \n");
    scanf("%d", &routeDuration);
    printf("Введите время отдыха на конечных остановках в минутах: \n");
    scanf("%d", &restTime);

    // Вывод расписания
    printSchedule(startHour, startMinute, endHour, endMinute, routeDuration, restTime);

    return 0;
}