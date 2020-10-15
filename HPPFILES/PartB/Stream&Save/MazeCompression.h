#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "../../PartA/Maze/Maze2d.h"
class MazeCompression {
public:
	MazeCompression() {};
	MazeCompression(std::vector<MultiTypes*> data = {}, std::string path = "");
	MazeCompression(const MazeCompression& comp);
	~MazeCompression() {};

	void compress();// דחיסה
	std::vector<MultiTypes*> dicompress(); //קבלת המקובץ

private:
	std::vector<MultiTypes*> m_data;
	std::string m_path;
};