#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1024

void func(const char *vivodtext, const char *zapis) {
    
    char text1[] = "для временного хранения.txt";
    FILE *file1, *file2;
    
    char buffer[N];

    file1 = fopen(vivodtext, "r");
    
    file2 = fopen(text1, "w");
    
    fputs(zapis, file2);

    while (fgets(buffer, sizeof(buffer), file1) != NULL) {
        fputs(buffer, file2);
    }

    
    fclose(file1);
    fclose(file2);

    remove(vivodtext);
    rename(text1, vivodtext);
}

int main() {
    const char *vivodtext = "вывод.txt";
    char line[N];
    char zapis[N]; 
    printf("Содержимое текстового файла:\n");
    const char *text2 = "вывод.txt";
    FILE *file3 = fopen(text2, "r");
    if(file3)
    {
        while((fgets(line, sizeof(line), file3))!=NULL)
        {
            printf("%s", line);
        }
        
        fclose(file3);
    } 

    printf("\nВведите строку: ");
    fgets(zapis, sizeof(zapis), stdin);
    
    zapis[strcspn(zapis, "\n")] = '\0';

    func(vivodtext, zapis);

    printf("Итоговая запись в файле:\n");
    FILE *file4 = fopen(text2,"r");
    if(file4)
    {
        while((fgets(line, sizeof(line), file4))!=NULL)
        {
            printf("%s", line);
        }
        
        fclose(file4);
    }
    return 0;
}
