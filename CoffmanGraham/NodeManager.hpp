#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iterator>

#include "Node.hpp"

class NodeManager
{
public:
	NodeManager() {};
	void addNode(Node& node);
	void addConnection(Node& n1, Node& n2);
	void loadData(const std::string& filename);

public:
	std::vector<Node> m_nodes{};
	size_t m_size{};
};