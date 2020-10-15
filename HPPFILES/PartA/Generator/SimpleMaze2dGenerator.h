#pragma once
#include "Maze2dGeneratorAbs.h"
class SimpleMaze2dGenerator: public Maze2dGeneratorAbs
{
public:
	virtual std::unique_ptr<Maze2d> generate(const std::string& name, int rows, int cols);
};

