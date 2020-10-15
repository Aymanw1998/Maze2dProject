#include "../../../HPPFILES/PartC/Commands/DirPathCommand.h"
void DirPathCommand::doCommand(std::vector<std::string> tokens)
{
	if (tokens.size() != 2)
		throw "Error in syntax: correct syntax -> 'dir <path>'";

	auto& path = tokens[1]; //path

	for(auto& p: fs::directory_iterator(path))
		m_view->print(p.path().string());
}
