#include <stdio.h>
#include <fcntl.h>
int argc;
char *argv[2];

main (int argc, char** argv) //аргументы командной строки 
{
    int fd; //файловый дескриптор (номер файла, с которым происходит работа в программе, используемой ОС)
    fd = open(argv[1],O_CREAT|O_WRONLY|O_TRUNC);
    dup2(fd,1);
    close(fd);
    execvp(argv[2], &argv[2]);
    perror("main");
}