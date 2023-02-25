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
	std::vector<device_address> get_all_addresses;
	void test_print();

private:
	void load_devices();

	std::vector<device_address> all_addresses;
	std::vector<device_address> get_addresses(pcap_if_t* dev_ptr);

	pcap_if_t* all_device_pointers;

};

