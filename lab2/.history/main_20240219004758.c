#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = malloc(5*sizeof(int));
    if(p == NULL)
    {
        printf("failed to allocate memory");
        return -1;
    }
    *p = 7;
    free(p);
    free(p);
    return 0;
}