#include <stdio.h>
#define N 80
 
int main() { 
    FILE *file;
    char str[N];
    int i;
    file = fopen("text.txt", "r");
 
    while ((str[i] = fgetc(file)) != EOF) {
        if (str[i] == '\n') {
            str[i] = '\0';
            printf("%s\n", str);
            i = 0;
        }
        else i++;
    }
    str[i] = '\0';
    printf("%s\n",str);
 
    fclose(file);
}
