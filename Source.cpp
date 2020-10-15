#include "HPPFILES/PartA/Generator/SimpleMaze2dGenerator.h"
#include "HPPFILES/PartA/Generator/Maze2dGeneratorAbs.h"
#include "HPPFILES/PartB/Stream&Save/MazeCompression.h"
#include "HPPFILES/PartA/Maze/Maze2d.h"
#include "HPPFILES/PartA/Infrastructure SearchAlgorithms/Maze2dState.h"
#include "HPPFILES/PartA/Infrastructure SearchAlgorithms/Maze2dSearchable.h"
#include "HPPFILES/PartA/Infrastructure SearchAlgorithms/BFS.h"
#include "HPPFILES/PartA/Infrastructure SearchAlgorithms/AStar.h"
#include "HPPFILES/PartA/Demo/Demo.h"
#include "HPPFILES/PartB/CLI/CLI.h"
//class TestMazeGenerator
//{
//public:
//	TestMazeGenerator() {};
//	void testMazeGenerator(Maze2dGenerator* mg) {
//
//		std::cout << "Time = " << mg->measureAlgorithmTime("Simple", 7,7) << std::endl;
//
//		std::unique_ptr<Maze2d> maze = mg->generate("Simple", 7,7);
//
//		Position p = maze->getStartPosition();
//		std::cout << "Position Start= " << p << std::endl;
//
//		std::cout << "Possible move in start = " << std::endl;
//		std::vector<std::string> ps = maze->getPossibleMove(p);
//		for (std::string x : ps) {
//			std::cout << x << " ";
//		}
//		std::cout << std::endl;
//
//		p = maze->getGoalPosition();
//		std::cout << "Position Goal = " << p << std::endl;
//		//cout << maze << endl;
//
//		std::cout << "Print the maze = " << std::endl;
//		std::cout << *maze;
//		std::cout << std::endl;
//		// ורק רוצים לחבר את המבוך לאלגורתם החיפוש
//		std::unique_ptr<State<Position>> sd = std::unique_ptr<Maze2dState>(new Maze2dState(maze->getStartPosition()));
//		std::unique_ptr<State<Position>> ed = std::unique_ptr<Maze2dState>(new Maze2dState(maze->getGoalPosition()));
//
//		
//		if (sd == ed) {
//			std::cout << "yes" << std::endl;
//		}
//		else {
//			std::cout << "No" << std::endl;
//
//		}
//
//		std::unique_ptr<Searchable<Position>> searchable = std::unique_ptr<Maze2dSearchable>(new Maze2dSearchable(maze));
//		std::cout << searchable->getStartState().getState() << std::endl;
//		std::cout << searchable->getGoalState().getState() << std::endl;
//		std::vector<State<Position>> possibleStates = searchable->getAllPossibleStates(searchable->getStartState());
//
//		for (int i = 0; i < (int)possibleStates.size(); i++) {
//			std::cout << possibleStates[i].getState() << std::endl;
//		}
//		std::unique_ptr<Searcher<Position>> bfs = std::unique_ptr<BFS<Position>>(new BFS<Position>());
//		auto s = bfs->search(searchable);
//		std::unique_ptr<Searcher<Position>> astarM = std::unique_ptr<AStar<Position>>(new AStar<Position>("M"));
//		Solution<Position> aM = astarM->search(searchable);
//		std::unique_ptr<Searcher<Position>> astarA = std::unique_ptr<AStar<Position>>(new AStar<Position>("A"));
//		Solution<Position> aA = astarA->search(searchable);
//
//		if (s == aM && aM == aA) {
//			std::cout << "Equals" << std::endl;
//		}
//	}
//};

int main() {
	CLI c(std::cin, std::cout);
	c.start();
	std::cin.get();
	return 0;

}