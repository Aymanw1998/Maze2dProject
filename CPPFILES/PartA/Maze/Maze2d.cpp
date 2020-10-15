#include "../../../HPPFILES/PartA/Maze/Maze2d.h"
Maze2d::Maze2d(const std::string& name, int rows, int cols) : m_name(name), m_rows(rows), m_cols(cols) {
	m_board.resize(m_rows);
	for (int i = 0; i < m_rows; i++)
		m_board[i].resize(m_cols);
	for (int i = 1; i < m_rows - 1; i++)
		for (int j = 1; j < m_cols - 1; j++) {
			m_board[1][j].top_wall = false;
			m_board[m_rows - 2][j].bot_wall = false;
			m_board[i][1].left_wall = false;
			m_board[i][m_cols - 2].right_wall = false;
		}
}

Maze2d::Maze2d(std::vector<MultiTypes*> data) {
	m_rows = *((int*)data[0]->get());
	m_cols = *((int*)data[1]->get());
	std::string* sp = static_cast<std::string*>(data[2]->get());
	m_name = *sp;
	for (auto& i : { 3 ,5 }) {
		int x = 0, y = 0;
		x = *((int*)data[i]->get());
		y = *((int*)data[i + 1]->get());
		if (i == 3) m_start = Position(x, y);
		else m_goal = Position(x, y);
	}
	m_board.resize(m_rows);
	for (int i = 0; i < m_rows; i++)
		m_board[i].resize(m_cols);
	int k = 7; int i = 0, j = 0;
	for (auto& vectorCell : m_board)
		for (auto& cell : vectorCell) {
			if (k == data.size()) continue;
			cell.display = *((char*)data[k++]->get());
		}
}





std::vector<std::string> Maze2d::getPossibleMove(Position& p) const {
	std::vector<std::string> possibleMoves;
	if (m_board[p.getY() - 1][p.getX()].display != '*')
		possibleMoves.push_back("Up");
	if (m_board[p.getY() + 1][p.getX()].display != '*')
		possibleMoves.push_back("Down");
	if (m_board[p.getY()][p.getX() + 1].display != '*')
		possibleMoves.push_back("Right");
	if (m_board[p.getY()][p.getX() - 1].display != '*')
		possibleMoves.push_back("Left");
	return possibleMoves;
}
std::vector<MultiTypes*> Maze2d::getData() {
	std::vector<MultiTypes*> data;
	data.push_back(new INT(m_rows));
	data.push_back(new INT(m_cols));
	data.push_back(new STRING(m_name));
	data.push_back(new INT(m_start.getX()));
	data.push_back(new INT(m_start.getY()));
	data.push_back(new INT(m_goal.getX()));
	data.push_back(new INT(m_goal.getY()));
	for (int i =0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			data.push_back(new CHAR(m_board[i][j].display));
	return data;
}

Position Maze2d::randomPosition() {
	return Position(((2 * rand()) + (m_rows)) % (m_cols - 1)
		, ((2 * rand()) + (m_rows)) % (m_cols - 1));
}

bool Maze2d::operator==(const Maze2d m) {
	if (m_name != m.m_name || !(m_start == m.m_start) || !(m_goal == m.m_goal) ||
		m_rows != m.m_rows || m_cols != m.m_cols)
		return false;
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)

			if (m_board[i][j].display != m.m_board[i][j].display)// זה עושה בעיות רק בסוף
				return false;
	return true;
}

std::ostream& operator<<(std::ostream& out, Maze2d maze2d)
{
	out << "Maze2d " << maze2d.getName() << std::endl;
	out << "Start:" << maze2d.getStartPosition() << " ";
	out << "Goal: " << maze2d.getGoalPosition() << std::endl;
	int rows = maze2d.getRows(); int cols = maze2d.getCols();
	auto board = maze2d.getBoard();
	for (int i = 0; i < rows; i++) {
		out << std::endl;
		for (int j = 0; j < cols; j++) {
			out << " " << board[i][j].display;
		}
	}
	return out;
}
