#include "../../../HPPFILES/PartC/Commands/GenerateMazeCommand.h"
void GenerateMazeCommand::doCommand(std::vector<std::string> tokens)
{
	if (tokens.size() != 4)
		throw "Error in syntax: correct syntax -> 'generate maze <name> <rows>'";

	m_model->generator(tokens[2], std::stoi(tokens[3]));

}