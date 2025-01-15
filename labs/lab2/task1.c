#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr[10];
    
    srand(time(NULL));
    
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 101; 
    }
    
    printf("Сгенерированный массив:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");

    return 0;
}
