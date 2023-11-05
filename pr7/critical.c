#include <stdio.h>
#include <signal.h>
main()
{
    void (*oldHandler)(); // the index on function appears
    printf("I can be <ctrl>+<c>\n");
    sleep(3);
    oldHandler = signal(SIGINT, SIG_IGN);
    printf("I am protected from <ctrl>+<c> now\n");
    sleep(3);
    signal(SIGINT, oldHandler);
    printf("I can be <ctrl>+<c> again\n");
    sleep(3);
    printf("bye\n");
}