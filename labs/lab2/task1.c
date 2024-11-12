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

  for (int i = n; i < 0; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  
  return 0;
}

