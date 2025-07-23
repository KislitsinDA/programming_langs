#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

typedef struct {
    char name[N];
    float price;
} Product;

int sort(const void *a, const void *b) {
    Product *productA = (Product *)a;
    Product *productB = (Product *)b;
    return (productA->price > productB->price) - (productA->price < productB->price);
}

int infile(const char *filename, Product *products) {
    FILE *file = fopen(filename, "r");
    int count = 0;
    while (fscanf(file, "%s %f", products[count].name, &products[count].price) == 2) {
        count++;
    }

    fclose(file);
    return count;
}

void zapis_itog(const char *filename, Product *products, int count) {
    FILE *file = fopen(filename, "w");

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %.2f\n", products[i].name, products[i].price);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {

    Product products[N];
    int count = infile(argv[1], products);

    qsort(products, count, sizeof(Product), sort);

    zapis_itog(argv[2], products, count);

    printf("Данные успешно отсортированы и записаны в файл %s.\n", argv[2]);
    return 0;
}
