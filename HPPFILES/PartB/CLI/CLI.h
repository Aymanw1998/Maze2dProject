#pragma once
#include <iostream>
#include "../../PartC/MVC/MyController.h"// עם רועי ש.ב. קשים רצח אבל ציונים סבבה ומבחן מעולה
#include "../../FonctionsForHelps.h"


class CLI {// לנהל לנו כל המערכת
private:
	std::istream& m_in;
	std::ostream& m_out;
	Controller* m_controller;
public:
	CLI(std::istream& in, std::ostream& out)
		: m_in(in), m_out(out), m_controller(nullptr){}
	~CLI() { delete m_controller; };
public:
	void start();
};