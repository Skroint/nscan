#pragma once
#include <string>
#include <stdio.h>
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <iphlpapi.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "console_color.h"

class target
{
public:
	// Fields
	std::string ip;
	std::string mac;
	std::string name;

	std::string adapter_ip;

	int adapter_idx;

	int ip_octets[4];

	bool ping;
	bool found;

	// Methods
	void print_row(int no);

	// Ctor
	target(std::string ip, std::string adapter_ip, int adapter_idx);
	target();

	~target();
private:
	int get_octet(std::string addr, int t);
	int find_nth(const std::string & haystack, size_t pos, const std::string & needle, int nth);
};

