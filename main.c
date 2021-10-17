/*
    Nathan Letourneau & Sarah Schlegel
    Game of life
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "cells.h"
#include "io.h"

#define MAP_SIZE 15

void initProg(void);

int main (void) {
    initProg();
    return 0;
}

void initProg (void) {
    Cell** map = initMap();
    int choice = 1;
    if (map == NULL) return ;
    printMap(map, stdout);
    while (choice) {
        printMenu() ;
        fflush(stdin) ;
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                freeMap(map) ;
                return;
            case 1:
                map = nextRound(map);
                printf("\n\n") ;
                printMap(map, stdout) ;
                break;
            case 2:
                saveToFile(map) ;
                break ;
        }
    }
}

Cell** allocMap () {
    Cell** map = malloc(sizeof(Cell*) * MAP_SIZE) ;
    for (size_t i = 0; i < MAP_SIZE; ++i) {
        map[i] = malloc(sizeof(Cell) * MAP_SIZE);

        if (map[i] == NULL) {
            printf("Error allocating\n") ;
            for (size_t j = i - 1 ; j >= 0 ; --j) {
                free(map[j]) ;
            }
            free(map) ;
            map = NULL ;
        }
    }
    return map;
}


Cell** initMap(){
    Cell** map = allocMap() ;
    if (map == NULL) {
        return NULL ;
    }
    srand(time(NULL));

    for (size_t i = 0; i < MAP_SIZE; ++i) {
        for (size_t j = 0; j < MAP_SIZE; j++) {
            map[i][j].status = rand() % 50 > 25 ? 1 : 0 ;
            setAliveOrDead(map[i][j].status, map[i][j].display) ;
        }
    }
    return map ;
}

void setAliveOrDead (int status, char *display) {
    if (status == 1) {
        strcpy(display, "Alive") ;
        return ;
    }
    strcpy(display, "Dead") ;
}

void printMap (Cell** map, FILE* stream) {
    for (size_t i = 0 ; i < MAP_SIZE ; ++i) {
        for (size_t j = 0 ; j < MAP_SIZE ; ++j) {
            fprintf(stream, " %d ", map[i][j].status);
        }
        fprintf(stream, "\n") ;
    }
}

Cell** nextRound (Cell** map) {
    size_t neighboursAlive = 0 ;
    Cell** mapTmp = allocMap() ;

    for (size_t i = 0; i < MAP_SIZE; ++i) {
        for (size_t j = 0; j < MAP_SIZE; ++j) {
            neighboursAlive = countNeighboursAlive(map, i, j) ;

            switch (map[i][j].status) {
                case 0:
                    if (neighboursAlive == 3) mapTmp[i][j].status = 1 ;
                    else mapTmp[i][j].status = 0 ;
                    break ;
                default:
                    if (neighboursAlive == 2 || neighboursAlive == 3) mapTmp[i][j].status = 1 ;
                    else mapTmp[i][j].status = 0 ;
            }
        }
    }

    freeMap(map) ;
    return mapTmp ;
}

size_t countNeighboursAlive (Cell** map, size_t i, size_t j) {
    size_t neighboursAlive = 0 ;
    for (short int x = -1; x <= 1; ++x) {
        for (short int y = -1; y <= 1; ++y) {
            if (i + x >= 0 && i + x < MAP_SIZE && j + y >= 0 && j + y < MAP_SIZE) {
                if (map[i+x][j+y].status == 1) neighboursAlive += 1 ;
            }
        }
    }
    if (map[i][j].status == 1) neighboursAlive -= 1 ;
    return neighboursAlive ;
}


void freeMap (Cell** map) {
    for (size_t i = 0 ; i < MAP_SIZE ; ++i) {
        if (map[i] != NULL) {
            free(map[i]) ;
            map[i] = NULL ;
        }
    }
    if (map != NULL) {
        free(map) ;
        map = NULL ;
    }
}
