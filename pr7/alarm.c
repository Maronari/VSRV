#include <stdio.h>
main()
{
    alarm(3); // заведен будильник на 3 сек
    printf("Looping forever\n");
    while (1);
    printf("This line should never be executed\n");
}
