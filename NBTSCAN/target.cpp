#include "target.h"



void target::print_row(int no)
{
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN);
	std::cout << "[" << no << "]\t";

	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << mac << "\t";
	std::cout << ip << "\t";
	if (ping)
	{
		SetConsoleColor(FOREGROUND_GREEN);
		std::cout << "YES\t";
	}
	else
	{
		SetConsoleColor(FOREGROUND_RED);
		std::cout << "NO\t";
	}

	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << name << "\t\t\n";

}

target::target(std::string ip, std::string adapter_ip, int adapter_idx)
{
	this->ip = ip;
	this->adapter_ip = adapter_ip;
	this->adapter_idx = adapter_idx;
	this->name = "<NOT FOUND>";

	// Set octets
	for (int t = 0; t < 4; t++)
		ip_octets[t] = get_octet(ip, t);

	found = false;
	ping = false;
}



target::target()
{
}


target::~target()
{
}

int target::get_octet(std::string addr, int t)
{
	int s = find_nth(addr, 0, ".", t - 1) + 1;
	if (t == 0) s = 0;

	int l = addr.size() - s - 0;
	if (t < 3) l = find_nth(addr, 0, ".", t) - s;

	std::string sub = addr.substr(s, l);
	return std::stoi(sub);
}

int target::find_nth(const std::string& haystack, size_t pos, const std::string& needle, int nth)
{
	size_t found_pos = haystack.find(needle, pos);
	if (0 == nth || std::string::npos == found_pos)  return found_pos;
	return find_nth(haystack, found_pos + 1, needle, nth - 1);
}
