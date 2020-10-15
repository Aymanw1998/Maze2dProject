#include "../../../HPPFILES/PartC/Commands/DisplayCommand.h"
void DisplayCommand::doCommand(std::vector<std::string> tokens)
{
	if (tokens.size() != 2)
		throw "Error in syntax: correct syntax -> 'display <name>'";

	Maze2d* maze = m_model -> display(tokens[1]);
	if (maze == nullptr)
	{
		m_view->print("Error: Maze with the name: "+ tokens[1] + " does not exist" );
		return;
	}
	std::ostringstream out;
	out << *maze;

	m_view->print(out.str());

	delete maze;
}