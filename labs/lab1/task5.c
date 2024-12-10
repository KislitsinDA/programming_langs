#include <stdio.h>
#define N 256
 
int main() { 
    FILE *file;
    char line[N];

    file = fopen("text.txt", "r");
    if(file)
    {
        while((fgets(line, sizeof(line), file))!=NULL)
        {
            printf("%s", line);
        }
        
        fclose(file);
    } 
    return 0;
}
