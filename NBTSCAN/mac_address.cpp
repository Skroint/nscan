#include "mac_address.h"
#include <sstream>
#include <iomanip>

mac_address mac_address::from_octets(uint8_t* src)
{
    mac_address address;

    memcpy(&address.octets, src, 4 * sizeof(uint8_t));

    return address;
}

std::string mac_address::to_string()
{
	std::stringstream ss;
	ss << std::hex;

	for (int i(0); i < 6; ++i)
	{
		ss << std::setw(2) << std::setfill('0') << (int)this->octets[i];
	}
		

	return ss.str();
}
