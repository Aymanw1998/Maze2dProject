#include "../../../HPPFILES/PartC/Commands/LoadMazeCommand.h"
void LoadMazeCommand::doCommand(std::vector<std::string> tokens)
{
	if (tokens.size() != 4)
		throw "Error in syntax: correct syntax -> 'load maze <file name> <name>'";
	m_model->loadMaze(tokens[3], tokens[2]);
}
