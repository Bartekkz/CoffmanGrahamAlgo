#pragma once

#include <vector>
#include <string>

typedef class Node Node;

class Node
{
public:
	Node() = default;

	Node(int idx, int l = 0, int sT = 0, int eT = 0, std::vector<Node> su = {}, std::vector<Node> pr = {})
		: m_index(idx), m_label(l), m_startTime(sT), m_endTime(eT), m_successors(su),
		m_predecessors(pr) {}
public:
	int m_index;
	int m_label;
	int m_startTime;
	int m_endTime;
	std::vector<Node> m_successors;
	std::vector<Node> m_predecessors;
};