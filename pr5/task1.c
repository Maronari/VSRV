#include <stdio.h>
#include <stdlib.h>

void func(int* arr, int arr_size) {
    int positive_val = 0;
    int negative_val = 0;
    int null_vall = 0;
    for (int i = 0; i < arr_size; i++)
    {
        if (*arr > 0) positive_val++;
        if (*arr < 0) negative_val++;
        if (*arr == 0) null_vall++;
        arr++;
    }
    printf("positive - %d, negative - %d, null - %d\n", positive_val, negative_val, null_vall);
}

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    
    int* array = (int*) malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        array[i] = rand()%50 - 25;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
    func(array, n);
    
    free(array);
}