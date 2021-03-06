#pragma once
#include "Command.h"
class LoadMazeCommand :public Command {
public:
	LoadMazeCommand(View* view, Model* model) :Command(view, model) {};
	~LoadMazeCommand() {};
public:
	virtual void doCommand(std::vector<std::string> tokens);
};