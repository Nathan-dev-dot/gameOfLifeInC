#include <stdio.h>
#include <stdlib.h>
#include "cells.h"
#include "io.h"

#define MAP_SIZE 15

void printMenu () {
    printf("Select option:\n") ;
    printf("0 - Quit\n") ;
    printf("1 - Next round\n") ;
    printf("2 - Save most recent to file.\n") ;
    printf("Enter : ") ;
}


void printMap (Cell** map, FILE* stream) {
    char outputChar[2] = {'O', 'X'} ;

    for (size_t i = 0 ; i < MAP_SIZE ; ++i) {
        for (size_t j = 0 ; j < MAP_SIZE ; ++j) {
            fprintf(stream, " %c ", outputChar[map[i][j].status]);
        }
        fprintf(stream, "\n") ;
    }
}

void saveToFile (Cell** map) {
    FILE* saveFile = fopen("output.txt", "w+") ;
    printMap(map, saveFile) ;
    fclose(saveFile) ;
}
