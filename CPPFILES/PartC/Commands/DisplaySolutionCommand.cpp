#include "../../../HPPFILES/PartC/Commands/DisplaySolutionCommand.h"

void DisplaySolutionCommand::doCommand(std::vector<std::string> tokens)
{
	if (tokens.size() != 3)
		throw "Error in syntax: correct syntax -> 'display solution <name>'";

	m_model->displaySolution(tokens[2]);
}
