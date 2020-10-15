#include "../../../HPPFILES/PartA/Generator/Maze2dGeneratorAbs.h"

std::string Maze2dGeneratorAbs::measureAlgorithmTime(const std::string& name, int size)
{
	const clock_t begin_time = clock();
	generate(name, size);
	int resualt = clock() - begin_time;
	return std::to_string(resualt);
}
