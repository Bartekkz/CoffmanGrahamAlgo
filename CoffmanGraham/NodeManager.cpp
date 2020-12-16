#include "NodeManager.hpp"

void NodeManager::addNode(Node& node)
{
	for (auto& n : m_nodes)
	{
		if (node.m_index == n.m_index)
		{
			perror("Node with this index already exist\n");
			exit(-1);
		}
	}
	m_nodes.push_back(node);
	m_size += 1;
}

void NodeManager::addConnection(Node& n1, Node& n2)
{
	if (n1.m_index == n2.m_index)
	{
		perror("Node cannot be connected to itself");
		exit(-1);
	}

	if (n1.m_index < n2.m_index)
	{
		perror("Node with smaller index needs to be first");
		exit(-1);
	}

	for (auto& node : m_nodes)
	{
		if (node.m_index == n1.m_index)
		{
			n1.m_predecessors.push_back(n2);
			n2.m_successors.push_back(n1);
		}
	}
}

void NodeManager::loadData(const std::string& filename)
{
	Node node;
	std::ifstream file;
	file.open(filename);
	std::string line;
	
	if (!file.is_open)
	{
		perror("Error during opening file");
		exit(-1);
	}
	
	while (std::getline(file, line))
	{
		std::istringstream iss{ line };
		std::vector<std::string> results((std::istream_iterator<std::string>()),
										  std::istream_iterator<std::string>());
		int index = std::stoi(results[0]);

		addNode();
	}
}