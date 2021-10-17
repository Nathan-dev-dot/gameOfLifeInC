typedef struct Cell {
    int status ;
    char display[15] ; //"Alive" ou "Dead"
} Cell;


Cell** initMap();
void setAliveOrDead(int status, char *display);
void freeMap (Cell** map) ;
void printMap (Cell** map, FILE* stream);
Cell** nextRound(Cell** map);
Cell** allocMap () ;
void saveCurrentMap (Cell** map) ;
size_t countNeighboursAlive (Cell** map, size_t i, size_t j);
