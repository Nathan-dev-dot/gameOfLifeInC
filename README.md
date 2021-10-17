# Game of Life

*Nathan Letourneau & Sarah Schlegel*
*October 2021*

## Description

The game of life is a little cellular automat created by John Horton Conway. A cellular automat is a set of cells represented by a 2D grid that evolves in time with basic rules. The Conway rules are the following:

- The neighbours of a cell are the 8 cells around.
- A dead cell having exactly three living neighbours becomes alive.
- A living cell having two or three living neighbours stays alive, otherwise it dies.



Setup
---

This project was inspired by the Java kata by MatthieuTDF (https://github.com/MatthieuTDF/GameOfLifeKata). We have designed a basic menu as following:

```
Select option:
0 - Quit
1 - Next round
2 - Save most recent to file.
Enter :
```

 The output is an array of 15x15 with the following design:

```
 O  O  O  O  O  X  X  O  O  O  O  O  X  O  O 
 X  O  O  X  X  O  X  X  X  X  X  X  X  O  X 
 O  O  X  O  X  X  X  O  O  O  O  X  X  X  O 
 O  X  X  O  O  X  O  X  X  X  X  X  O  X  X 
 O  X  O  X  X  X  X  X  X  O  X  O  O  X  X 
 X  O  X  O  X  O  O  X  X  X  O  X  X  X  X 
 X  O  X  O  O  X  O  O  X  O  X  O  X  O  O 
 O  O  O  X  X  O  X  X  O  O  O  O  O  O  O 
 X  X  O  O  X  O  X  X  X  O  X  X  O  X  O 
 O  X  O  X  O  O  O  O  O  O  O  X  O  O  X 
 X  X  X  O  O  X  O  O  X  O  O  X  X  X  O 
 O  X  X  X  O  X  O  O  X  X  O  O  X  X  X 
 X  O  O  O  O  X  O  O  X  X  X  X  O  X  X 
 O  X  X  O  O  O  X  O  O  X  X  X  O  X  O 
 O  X  X  O  X  X  O  X  O  X  X  X  X  O  X 
```

where `X` represents a living cell and `O` a dead cell.

The current state can be saved is saved to an `output.txt` file, it overwrites the previous output.

