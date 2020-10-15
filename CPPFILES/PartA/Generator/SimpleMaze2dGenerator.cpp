#include "../../../HPPFILES/PartA/Generator/SimpleMaze2dGenerator.h"

std::unique_ptr<Maze2d> SimpleMaze2dGenerator::generate(const std::string& name, int rows, int cols) {
   
    if (rows % 2 == 0) rows++;
    else rows += 2;
    if (cols % 2 == 0) cols++;
    else cols += 2;
     std::unique_ptr<Maze2d> maze = std::unique_ptr<Maze2d>(new Maze2d(name, rows, cols));

     std::vector<std::vector<Cell>> Level = maze->getBoard();
     for (int i = 1; i + 1 < rows; i++) {
         for (int j = 1; j + 1 < cols; j++) {
             Level[i][j].display = ((rand() % 2 == 1) ? ' ' : '*');
         }
     }
     return maze;
}