#pragma once
#include <string>
#include <stdint.h>

class ipv4_address
{
public:
	static ipv4_address from_octets(uint8_t* src);
	static ipv4_address from_string(std::string str);
	
	std::string to_string();
	uint8_t octets[4];

};

