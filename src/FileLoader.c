#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


FILE* FileLoader(FILE *FPointer, char* FileName){
    errno = 0;
    FPointer = fopen(FileName, "r");

    if (FPointer == NULL){
        perror("Error");
        fprintf(stderr, "%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    else{
        return FPointer;
    }
}

