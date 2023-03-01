#pragma once
#include <string>
#include "ipv4_address.h"
#include "mac_address.h"
#include "ipv4_range.h"
#include <pcap.h>


class device_address
{
public:
	std::string device_name;
	std::string device_description;

	ipv4_address ip;
	ipv4_address mask;
	mac_address mac;

	ipv4_range get_range();


};

