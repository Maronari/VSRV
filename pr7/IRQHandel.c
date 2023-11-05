#include <stdio.h>
#include <signal.h>

void MyAlarm(int var)
{
    printf("End work");
    _Exit(0); // Завершение работы программы
}

int main(void)
{
    puts("Start work");
    // Привязка функции MyAlarm к сигналу SIGALRM
    signal(SIGALRM, MyAlarm);
    // Установка будильника на 10 секунд
    alarm(10);
    // Бесконечный цикл
    while (1)
    {
    }
    return 0;
}
