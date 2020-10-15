#include "../../../HPPFILES/PartC/Commands/SaveMazeCommand.h"
void SaveMazeCommand::doCommand(std::vector<std::string> tokens)
{
	if (tokens.size() != 4)
		throw "Error in syntax: correct syntax -> 'save maze <name> <file name>'";

	m_model->saveMaze(tokens[2], tokens[3]);
}
