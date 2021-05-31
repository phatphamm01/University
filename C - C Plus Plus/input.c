#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define inLine 100000

void getFile(char name[], char **result){
    int n = 0;
    char *line = (char *)malloc(inLine * sizeof(char));

    FILE *fp;
    fp = fopen(name, "a+");
    while (fgets(line, inLine, (FILE *)fp))
    {
        n += strlen(line);
        *result = (char *)realloc(*result, n * sizeof(char));
        strcat(*result, line);
    }
    fclose(fp);

    free(line);
}

int main()
{
    char *input = (char *)malloc(1 * sizeof(char));
    getFile("demo.txt", &input);
    printf("%s", input);

    free(input);
    return 0;
}