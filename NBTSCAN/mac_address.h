#pragma once
#include <stdint.h>
#include <string>

class mac_address
{
public:
	static mac_address from_octets(uint8_t* src);


	std::string to_string();
	uint8_t octets[6];
};

