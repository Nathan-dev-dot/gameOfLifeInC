#include <stdio.h>
#include "cells.h"
#include "io.h"

void printMenu () {
    printf("Select option:\n") ;
    printf("0 - Next round\n") ;
    printf("1 - Next round\n") ;
    printf("2 - Save most recent to file.\n") ;
    printf("Enter : ") ;
}

size_t saveToFile (Cell** map) {
    FILE* saveFile = fopen("output.txt", "w+") ;
    printMap(map, saveFile) ;
    fclose(saveFile) ;
    return 1 ;
}
