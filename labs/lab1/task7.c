#include <stdio.h>
#include <stdlib.h>
#define N 1024
int main() {
    char line[N];

    const char *text = "text.txt";
    char *str = "привет";
    printf("Содержимое файла:\n");
    FILE *file1 = fopen(text, "r");
    if(file1)
    {
        while((fgets(line, sizeof(line), file1))!=NULL)
        {
            printf("%s", line);
        }
        
        fclose(file1);
    } 
    FILE *file2 = fopen(text, "a");
    fputs(str,file2);
    printf("\n");
    fclose(file2);
    
    printf("Содержимое файла после записи:\n");
    FILE *file3 = fopen(text,"r");
    if(file3)
    {
        while((fgets(line, sizeof(line), file3))!=NULL)
        {
            printf("%s", line);
        }
        
        fclose(file3);
    } 
    
    return 0;
}
