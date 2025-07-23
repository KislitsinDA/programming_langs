#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Написать программу, которая в качестве аргумента принимает размер произвольного массива, 
создает его, заполняет случайными числами с плавающей точкой в интервале (arg1, arg2), где arg1 и arg2 - также аргументы, 
вводимые при запуске программы, и выводит массив в консоль. Далее программа записывает массив в файл в отсортированном виде.

Сортировка должна быть организована с помощью функции.*/

int sortirovka(const void *a, const void *b) {
    return (*(float *)a > *(float *)b) - (*(float *)a < *(float *)b);
}

void randmas(float *arr, int n, float arg1, float arg2) {
    for (int i = 0; i < n; i++) {
        arr[i] = arg1 + (float)rand() / RAND_MAX * (arg2 - arg1);
    }
}

void zapisvfile(const char *zapis, float *arr, int n) {
    FILE *file = fopen(zapis, "w");

    for (int i = 0; i < n; i++) {
        fprintf(file, "%f\n", arr[i]);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    float arg1 = atof(argv[2]);
    float arg2 = atof(argv[3]);

    float *arr = (float *)malloc(n * sizeof(float));
    
    srand(time(NULL));

    randmas(arr, n, arg1, arg2);

    printf("Случайный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%f\n", arr[i]);
    }

    qsort(arr, n, sizeof(float), sortirovka);
    
    zapisvfile("сортировка.txt", arr, n);

    printf("Отсортированный массив записан в файл\n");

    return 0;
}
