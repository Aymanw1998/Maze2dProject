#pragma once
#include <iostream>
#include <vector>
#include "State.h"
template <class T>
class Solution
{
public:
	Solution(): m_counterDevelopments(0) {};
	Solution(const Solution& s) {
		for (auto& x : s.m_solution)
		{
			m_solution.push_back(x);
		}
		this->m_counterDevelopments = s.m_counterDevelopments;
	}
	~Solution() {};
public:
	std::vector<State<T>> getSolution() const { return m_solution; }
	void addSolution(const State<T>& s) { m_solution.push_back(s); }
	void setCounter(const int counter) { m_counterDevelopments = counter; }

	int getSize() { return m_solution.size(); }
	int getCounterDevelop() const { return m_counterDevelopments; }
public:
	bool operator== (const Solution solution) {
		if (m_solution.size() != solution.m_solution.size())
			return false;
		for (int i = 0; i < (int)m_solution.size(); i++)
			if (m_solution[i] != solution.m_solution[i])
				return false;
		return true;
	}
	friend std::ostream& operator<< (std::ostream& out, const Solution& s)
	{
		// temp = {goal, ......,start}
		auto temp = s.getSolution();
		int size = temp.size();
		while (!temp.empty()) {
			size--;
			if (size)
				out << temp.back() << "->";
			else out << temp.back() << std::endl;
			temp.pop_back();
		}
		return out;
	}
private:
	std::vector<State<T>> m_solution; // מסלול הכי טוב
	int m_counterDevelopments = 0;// כמה פתיח האלגורתם חיפוש עד שמצא את הפתרון
};

