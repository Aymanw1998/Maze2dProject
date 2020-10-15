#include "../../../HPPFILES/PartC/Commands/MazeSizeCommand.h"

void MazeSizeCommand::doCommand(std::vector<std::string> tokens)
{
	if (tokens.size() != 3)
		throw "Error in syntax: correct syntax -> 'maze size <name>'";

	m_model->sizeMaze(tokens[2]);
}
