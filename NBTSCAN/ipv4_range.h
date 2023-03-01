#pragma once
#include "ipv4_address.h"
#include <vector>

class ipv4_range
{
public:
	ipv4_range(ipv4_address from, ipv4_address to);
	ipv4_range();

	ipv4_address from;
	ipv4_address to;

	std::vector<ipv4_address> get_addresses();
	void print();
};

