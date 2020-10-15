#pragma once
#include "Maze2dGenerator.h"
#include <ctime>
class Maze2dGeneratorAbs: public Maze2dGenerator 
{
public:
	virtual std::unique_ptr<Maze2d> generate(const std::string& name, int size) = 0;
	virtual std::string measureAlgorithmTime(const std::string& name, int size);
};

