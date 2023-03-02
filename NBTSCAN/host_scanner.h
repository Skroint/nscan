#pragma once
#include <vector>
#include <string>
#include "scan_result.h"
#include "ipv4_address.h"

class host_scanner
{
public:
	virtual std::vector<std::string> scan(std::vector<std::string> targets);

	virtual void scan(scan_result* sr, const std::vector<ipv4_address>& addresses);

};

