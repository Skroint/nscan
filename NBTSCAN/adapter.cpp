#include "adapter.h"



void adapter::print_line()
{
	// Interface title
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	std::cout << "Interface ";
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN);
	std::cout << "[" << ip << "]";
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	std::cout << " : ";
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN);
	std::cout << "[" << netmask << "]\n\n";

	// Header
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	std::cout << "No\t";
	std::cout << "MAC address\t\t";
	std::cout << "IP address\t";
	std::cout << "PING\t";
	std::cout << "NetBIOS name\n";
	std::cout << "--------------------------------------------------------------------------\n";

	// All targets
	int no = 0;
	for (int t = 0; t < 255; t++)
	{
		if (targets[t].found)
		targets[t].print_row(no++);
	}
}

adapter::adapter(std::string ip, std::string netmask, int index)
{
	this->ip = ip;
	this->netmask = netmask;
	this->index = index;

	// Set octets
	for (int t = 0; t < 4; t++) 
		ip_octets[t] = get_octet(ip, t);
	for (int t = 0; t < 4; t++)
		netmask_octets[t] = get_octet(netmask, t);

	// Init target array
	targets = new target[255];

	for (int t = 0; t < 255; t++)
	{
		std::string t_ip = std::to_string(ip_octets[0]);
		t_ip += ".";
		t_ip += std::to_string(ip_octets[1]);
		t_ip += ".";
		t_ip += std::to_string(ip_octets[2]);
		t_ip += ".";
		t_ip += std::to_string(t);
		targets[t] = target(t_ip, ip, index);
	}

}

adapter::adapter()
{
}


adapter::~adapter()
{
}

int adapter::get_octet(std::string addr, int t)
{
	int s = find_nth(addr, 0, ".", t - 1) + 1;
	if (t == 0) s = 0;

	int l = addr.size() - s - 0;
	if (t < 3) l = find_nth(addr, 0, ".", t) - s;
	
	std::string sub = addr.substr(s, l);
	return std::stoi(sub);
}

int adapter::find_nth(const std::string& haystack, size_t pos, const std::string& needle, int nth)
{
	size_t found_pos = haystack.find(needle, pos);
	if (0 == nth || std::string::npos == found_pos)  return found_pos;
	return find_nth(haystack, found_pos + 1, needle, nth - 1);
}
