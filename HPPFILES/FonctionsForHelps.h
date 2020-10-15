#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <filesystem>
#include <sstream> 

namespace fs = std::filesystem;
class FonctionsForHelps
{
public:
	std::vector<std::string> arrayWords(std::string line)
	{
		// מחלק את המחרוזת שיש בה רווחים לוקטור ששומר כל מילה בתא
		std::vector<std::string> tokens;
		std::stringstream check(line);
		std::string intermediate;
		while (std::getline(check, intermediate, ' '))
			tokens.push_back(intermediate);
		return tokens;
	}
};

