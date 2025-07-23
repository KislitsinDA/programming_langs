#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    srand(time(NULL));
    
    int mas = atoi(argv[1]);

    float *arr = (float *)malloc(mas * sizeof(float));

    srand(time(NULL));

    for (int i = 0; i < mas; i++) {
        arr[i] = (float)rand() / RAND_MAX; 
    }

    printf("Случайный массив:\n");
    for (int i = 0; i < mas; i++) {
        printf("%f\n", arr[i]);
    }

    free(arr);

    return 0;
}
