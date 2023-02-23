#pragma once
#include <string>
#include "ipv4_address.h"
#include <pcap.h>

class device_address
{
public:
	static device_address from_addr_ptr(pcap_addr_t* addr_ptr,
		pcap_if_t* dev_ptr);
	
	std::string device_name;
	std::string device_description;

	ipv4_address ip;
	ipv4_address mask;

private:
	pcap_addr_t* addr_ptr;
	pcap_if_t* dev_ptr;

};

