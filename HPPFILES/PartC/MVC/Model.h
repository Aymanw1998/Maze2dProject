#pragma once
#include "../../PartA/Maze/Maze2d.h"
#include "Observable.h"
#include "Observer.h"
#include <map>
class Model: public Observable  {
public:
	Model() {};
	Model(const Model& m) {};
	~Model() {};
public:
	virtual void generator(const std::string name, int size) = 0;
	virtual Maze2d* display(const std::string name) = 0;
	virtual void saveMaze(const std::string name, const std::string path) = 0;
	virtual void loadMaze(const std::string name, const std::string path) = 0;
	virtual void sizeMaze(const std::string name) = 0;
	virtual void sizeFile(const std::string name) = 0;
	virtual void solve(const std::string name, const std::string alg) = 0;
	virtual void displaySolution(const std::string name) = 0;
	virtual std::vector<std::string> namesMazes() = 0;
	//virtual std::vector<std::string> namesSolutions() = 0;
};