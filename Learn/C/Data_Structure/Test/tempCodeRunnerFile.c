#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    const char *filename = "test.csv";
    const char *data = "2202203,Chin Wai San,102\n";
    
    if ((fp = fopen(filename, "w+")) == NULL)
    {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    int result = fprintf(fp, data);
    if (result < 0)
    {
        printf("Error writing data to file %s\n", filename);
        exit(2);
    }
    fclose(fp);
    return 0;
}