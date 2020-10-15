#include "../../../HPPFILES/PartC/Commands/FileSizeCommand.h"

void FileSizeCommand::doCommand(std::vector<std::string> tokens)
{
	if (tokens.size() != 3)
		throw "Error in syntax: correct syntax -> 'file size <name>'";

	m_model->sizeFile(tokens[2]);
}
