#pragma once
#include <pcap.h>
#include <string>
#include <vector>
#include "device_address.h"

class device
{
public:
	std::vector<device_address> addresses;

	device(pcap_if_t* ptr);
	

private:
	pcap_if_t* dev_ptr;
};

