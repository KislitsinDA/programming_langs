#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  int n = 10;
  srand(time(NULL));
  int array[n];
  for (int i = 0; i < n; i++) {
    array[i] = rand() % 100;
  }

  FILE *fp = fopen("nums.txt", "w");
  if (fp == NULL) {
    printf("Ошибка открытия файла!\n");
    return 1;
  }

  for (int i = n - 1; i >= 0; i--) {
    fprintf(fp, "%d\n", array[i]);
  }

  fclose(fp);
  printf("Числа записаны в файл 'nums.txt' в обратном порядке.\n");
  return 0;
}
