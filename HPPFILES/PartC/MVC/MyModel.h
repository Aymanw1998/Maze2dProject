#pragma once
#include <map>
#include "Model.h"
#include "../../PartA/Infrastructure SearchAlgorithms/Solution.h"
#include "../../PartA/Infrastructure SearchAlgorithms/BFS.h"
#include "../../PartA/Infrastructure SearchAlgorithms/AStar.h"
#include "../../PartA/Infrastructure SearchAlgorithms/Maze2dSearchable.h"
class MyModel :public Model {
private: // model
	std::map<std::string, std::unique_ptr<Maze2d>> m_mazes; // עכשיו מייצג מבוך
	std::map<std::string, std::unique_ptr<Solution<Position>>> m_solutionMazes;
public:
	MyModel() :Model() {}
	~MyModel() {}
	virtual void generator(const std::string name, int rows);
	virtual Maze2d* display(const std::string name);
	virtual void saveMaze(const std::string name, const std::string path);
	virtual void loadMaze(const std::string name, const std::string path);
	virtual void sizeMaze(const std::string name);
	virtual void sizeFile(const std::string name);
	virtual void solve(const std::string name, const std::string alg);
	virtual void displaySolution(const std::string name);
	virtual std::vector<std::string> namesMazes();
	//virtual std::vector<std::string> namesSolutions();
};