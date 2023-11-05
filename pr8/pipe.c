#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int pfd[2];
    pid_t cpid;
    char buf;
    assert(argc == 2);
    if (pipe(pfd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    cpid = fork();
    if (cpid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (cpid == 0)
    {                  /* Потомок - читает из канала*/
        close(pfd[1]); /* Закрывает неиспользуемый write канала*/
        while (read(pfd[0], &buf, 1) > 0)
            write(STDOUT_FILENO, &buf, 1);
        write(STDOUT_FILENO, "\n", 1);
        close(pfd[0]);
        _exit(EXIT_SUCCESS);
    }
    else
    {                  /* Родитель – записывает argv[1] в канал */
        close(pfd[0]); /* Закрывает неиспользуемый read канала */
        write(pfd[1], argv[1], strlen(argv[1]));
        close(pfd[1]); /* читатель увидит EOF */
        wait(NULL);    /* ожидает завершения потомка */
        exit(EXIT_SUCCESS);
    }
}