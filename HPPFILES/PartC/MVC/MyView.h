#pragma once
#include "View.h"

class MyView : public View {
private:
	std::istream& m_in;
	std::ostream& m_out;
public:
	MyView(std::istream& in, std::ostream& out) :View(), m_in(in), m_out(out) {};
	~MyView() {};
	virtual void print(std::string str) {
		m_out << str << std::endl;
	}
	virtual std::string input() {
		std::string s;
		std::getline(m_in, s);
		return s;
	}
};