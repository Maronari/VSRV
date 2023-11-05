#include <stdio.h>
#include <fcntl.h>
#define MAX_COUNT 200

void  ChildProcess(void); /* child process prototype  */
void  ParentProcess(void); /* parent process prototype */

void ParentProcess(void) {
    for (int i = 0; i < MAX_COUNT; i++)
    {
        /* code */
        printf("This line is from parent, value = %d\n", i);
    }
}

void ChildProcess(void) {
    for (int i = 0; i < MAX_COUNT; i++)
    {
        /* code */
        printf("This line is from child, value = %d\n", i);
    }
}

int main(int argc, char** argv) {
    if (fork(0) == 0) {
        ChildProcess();
    } else {
        ParentProcess();
    }
    return 0;
}