#include "../../../HPPFILES/PartA/Generator/MyMaze2dGenerator.h"
#include <algorithm>


std::unique_ptr<Maze2d> MyMaze2dGenerator::generate(const std::string& name, int size) {
    if (size % 2 == 0) size++;
    else size += 2;
   
    std::unique_ptr<Maze2d> maze = std::unique_ptr<Maze2d>(new Maze2d(name, size, size));

    std::vector<std::vector<Cell>> Level = maze->getBoard();


    srand((unsigned)time(NULL));
    int random = 0;
    Position start = maze->randomPosition();
    maze->setStartPosition(start);


    int visitedCells = 1;
    int totalCells = ((size - 1) / 2) * ((size - 1) / 2);
    int percent = 0;
    std::stack<int> back_trackX, back_trackY;
    int randomX = start.getX(), randomY = start.getY();
    Level[randomY][randomX].visited = true;

    while (visitedCells < totalCells)
    {
        if ((randomY >= 2 && Level[randomY - 2][randomX].visited == false && Level[randomY][randomX].top_wall == true && Level[randomY - 2][randomX].bot_wall == true) ||
            (randomY < size - 2 && Level[randomY + 2][randomX].visited == false && Level[randomY][randomX].bot_wall == true && Level[randomY + 2][randomX].top_wall == true) ||
            (randomX >= 2 && Level[randomY][randomX - 2].visited == false && Level[randomY][randomX].left_wall == true && Level[randomY][randomX - 2].right_wall == true) ||
            (randomX < size - 2 && Level[randomY][randomX + 2].visited == false && Level[randomY][randomX].right_wall == true && Level[randomY][randomX + 2].left_wall == true))
        {
            random = (rand() % 4) + 1;

            // GO UP
            if ((random == 1) && (randomY > 1)) {
                if (Level[randomY - 2][randomX].visited == false) {
                    Level[randomY - 1][randomX].display = ' ';
                    Level[randomY - 1][randomX].visited = true;
                    Level[randomY][randomX].top_wall = false;

                    back_trackX.push(randomX);          // Push X for back track
                    back_trackY.push(randomY);          // Push Y for back track

                    randomY -= 2;                   // Move to next cell
                    Level[randomY][randomX].visited = true;     // Mark cell moved to as visited
                    Level[randomY][randomX].display = ' ';      // Update path
                    Level[randomY][randomX].bot_wall = false;   // Knock down wall
                    visitedCells++;                 // Increase visitedCells counter
                }
                else
                    continue;
            }

            // GO DOWN
            else if ((random == 2) && (randomY < size - 2)) {
                if (Level[randomY + 2][randomX].visited == false) {
                    Level[randomY + 1][randomX].display = ' ';
                    Level[randomY + 1][randomX].visited = true;
                    Level[randomY][randomX].bot_wall = false;
                    back_trackX.push(randomX);
                    back_trackY.push(randomY);
                    randomY += 2;
                    Level[randomY][randomX].visited = true;
                    Level[randomY][randomX].display = ' ';
                    Level[randomY][randomX].top_wall = false;
                    visitedCells++;
                }
                else
                    continue;
            }

            // GO LEFT
            else if ((random == 3) && (randomX > 1)) {
                if (Level[randomY][randomX - 2].visited == false) {
                    Level[randomY][randomX - 1].display = ' ';
                    Level[randomY][randomX - 1].visited = true;
                    Level[randomY][randomX].left_wall = false;

                    back_trackX.push(randomX);
                    back_trackY.push(randomY);

                    randomX -= 2;
                    Level[randomY][randomX].visited = true;
                    Level[randomY][randomX].display = ' ';
                    Level[randomY][randomX].right_wall = false;
                    visitedCells++;
                }
                else
                    continue;
            }

            // GO RIGHT
            else if ((random == 4) && (randomX < size - 2)) {
                if (Level[randomY][randomX + 2].visited == false) {
                    Level[randomY][randomX + 1].display = ' ';
                    Level[randomY][randomX + 1].visited = true;
                    Level[randomY][randomX].right_wall = false;
                    back_trackX.push(randomX);
                    back_trackY.push(randomY);
                    randomX += 2;
                    Level[randomY][randomX].visited = true;
                    Level[randomY][randomX].display = ' ';
                    Level[randomY][randomX].left_wall = false;
                    visitedCells++;
                }
                else
                    continue;
            }
        }
        else {
            randomX = back_trackX.top(); back_trackX.pop();
            randomY = back_trackY.top(); back_trackY.pop();
        }
    }
    Position goal = maze->randomPosition();
    maze->setGoalPosition(goal);

    if (goal == start) {
        int endx = goal.getX();
        if (endx < size - 2) { endx++; }
        else if (endx == size - 1) { endx--; }
        randomX = endx;
        maze->setGoalPosition(randomY, randomX);
        goal = maze->getGoalPosition();
    }
    Level[start.getY()][start.getX()].display = 'S';
    Level[goal.getY()][goal.getX()].display = 'G';

    maze->setBoard(Level);
    return maze;


}
