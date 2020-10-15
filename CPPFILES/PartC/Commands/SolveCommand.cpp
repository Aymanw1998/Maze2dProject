#include "../../../HPPFILES/PartC/Commands/SolveCommand.h"

void SolveCommand::doCommand(std::vector<std::string> tokens)
{
	if (tokens.size() != 3)
		throw "Error in syntax: correct syntax -> 'display solution <name>'";

	m_model->solve(tokens[1], tokens[2]);
}
