#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX 100

char** split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;


    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }


    count += last_comma < (a_str + strlen(a_str) - 1);

    
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

int main()
{
    FILE* InputFile = fopen("input.txt", "r");
    const int n;
    
    
    if (!InputFile)
    {
        printf("ERROR\nPlease check if you named the file correctly. It should be called:\ninput.txt\n");
    }
    
    else
    {
        fscanf(InputFile, "%d", &n);
        char** row[n];
        char nado[n];
        char a[n];

        if (fgets(nado, 2, InputFile) != NULL);
        for (int r = 0; r < n; r++)
        {
            if (fgets(a, MAX, InputFile) != NULL)
            {
                printf("%s\n",a);
                row[r]=split(a, '+');
                printf("%s\n",row);
                for(int i=0;i<(sizeof(row[0])/sizeof(row[0][0]));i++)
                {
                    printf("%s",row[0][i]);
                }
            }
            else
            {
                printf("Error in entered data in file");
                break;
            }
        }
        fclose(InputFile);
    }
}