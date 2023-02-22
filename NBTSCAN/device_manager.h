#pragma once
#include <pcap.h>
#include <vector>
#include "device.h"

class device_manager
{
public:
	device_manager();
	~device_manager();
	void print_all_devices();

	

private:
	void ifprint(pcap_if_t* d);
	const char* iptos(sockaddr* sockaddr);

	void load_devices();

	std::vector<device> all_devices;
	pcap_if_t* all_device_pointers;

};

