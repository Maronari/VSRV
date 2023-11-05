#include <stdio.h>

void never_call(void) {
    printf("[*] wow how did you magane to call this?\n");
    return;
}

void main (int argc, char** argv) {
    printf("[*] you ran this binary!\n");
    return 0;
}