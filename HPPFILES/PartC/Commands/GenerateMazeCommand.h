#pragma once
#include "Command.h"
class GenerateMazeCommand :public Command {
public:
	GenerateMazeCommand(View* view, Model* model) :Command(view, model) {};
	~GenerateMazeCommand() {};
public:
	virtual void doCommand(std::vector<std::string> tokens);
};

