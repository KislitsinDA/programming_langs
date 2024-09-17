#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 256

int main() {
    FILE *file1, *file2;
    char line[MAX_LINE_LENGTH];
    int sch = 0;

    file1 = fopen("text.txt", "r");
    file2 = fopen("text1.txt", "w");
    while (fgets(line, sizeof(line), file1) != NULL && sch < 3) {
        fputs(line, file2);
        sch++;
    }
    fclose(file1);
    fclose(file2);
    return 0;
}
