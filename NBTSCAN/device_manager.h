#pragma once
#include <pcap.h>
#include <vector>
#include "device_address.h"

class device_manager
{
public:
	device_manager();
	~device_manager();
	void print_all_addresses();
	device_address get_device_address();

private:
	
	void load_devices();


	std::vector<device_address> all_addresses;
	

};

