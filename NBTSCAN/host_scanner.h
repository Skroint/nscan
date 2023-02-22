#pragma once
#include <vector>
#include <string>

class host_scanner
{
public:
	virtual std::vector<std::string> scan(std::vector<std::string> targets);

};

