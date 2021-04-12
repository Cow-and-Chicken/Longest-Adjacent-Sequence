#include <stdio.h>
#include "longestSequence.h"

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("Error");
        return 1;
    }
    int counter;
    for (counter = 1; counter < argc; counter++)
    {
        printf("%d. ", counter);
        fileInput(argv[counter]);
    }
    return 0;
}