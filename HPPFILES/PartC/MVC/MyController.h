#pragma once
#include "Controller.h"
#include "MyModel.h"
#include "MyView.h"
#include "../Commands/DirPathCommand.h"
#include "../Commands/GenerateMazeCommand.h"
#include "../Commands/DisplayCommand.h"
#include "../Commands/SaveMazeCommand.h"
#include "../Commands/LoadMazeCommand.h"
#include "../Commands/MazeSizeCommand.h"
#include "../Commands/FileSizeCommand.h"
#include "../Commands/SolveCommand.h"
#include "../Commands/DisplaySolutionCommand.h"
class MyController : public Controller {
public:
	MyController(View* view, Model* model);


	// Inherited via Controller
	virtual Command* get(const std::string& command);
	virtual void update(const std::string msg);
};