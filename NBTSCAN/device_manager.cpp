#include "device_manager.h"
#include <string>
#include <iostream>
#include <iphlpapi.h>
#include <sstream>
#include <iomanip>
device_manager::device_manager()
{
	load_devices();
}


void device_manager::load_devices()
{
	char error_buffer[PCAP_ERRBUF_SIZE + 1];

	if (pcap_findalldevs(&all_device_pointers, error_buffer) == -1)
	{
		fprintf(stderr, "Error in pcap_findalldevs: %s\n", error_buffer);
	}

	for (pcap_if_t* d = all_device_pointers; d; d = d->next)
	{
		for (auto address : get_addresses(d))
		{
			this->all_addresses.push_back(address);
		}
	}
}

std::vector<device_address> device_manager::get_addresses(pcap_if_t* dev_ptr)
{
	std::vector<device_address> addresses;


	// Iterate through all addresses on the device
	for (pcap_addr_t* a = dev_ptr->addresses; a; a = a->next)
	{
		// Make sure it is an IPV4 Address
		if (a->addr->sa_family != AF_INET)
		{
			continue;
		}

		// Make sure there is an address and a netmask
		if (a->addr &&
			a->netmask)
		{
			addresses.push_back(device_address::from_addr_ptr(a, dev_ptr));
		}
	}



	return addresses;
}


device_manager::~device_manager()
{
	pcap_freealldevs(all_device_pointers);
}

void device_manager::print_all_addresses()
{
	int index = 0;
	for (auto address : all_addresses)
	{
		std::cout << "[" << index << "] ";
		std::cout << address.device_name << " " << address.ip.to_string() << " " << address.mask.to_string() << std::endl;
		index++;
	}
}

std::string hexStr(const uint8_t* data, int len)
{
	std::stringstream ss;
	ss << std::hex;

	for (int i(0); i < len; ++i)
		ss << std::setw(2) << std::setfill('0') << (int)data[i];

	return ss.str();
}

void device_manager::test_print()
{
	IP_ADAPTER_INFO* pAdapterInfo = nullptr;
	ULONG ulOutBufLen = 0;
	
	if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW)
	{
		free(pAdapterInfo);
		pAdapterInfo = (PIP_ADAPTER_INFO)malloc(ulOutBufLen);
	}
	GetAdaptersInfo(pAdapterInfo, &ulOutBufLen);
	
	while (pAdapterInfo)
	{
		std::cout << "Name: " << pAdapterInfo->AdapterName << std::endl;
		std::cout << "Desc: " << pAdapterInfo->Description << std::endl;

		IP_ADDR_STRING* address = &pAdapterInfo->IpAddressList;
		while (address)
		{
			std::cout << "IP: " << address->IpAddress.String << std::endl;
			std::cout << "Mask: " << address->IpMask.String << std::endl;

			address = address->Next;
		}
		std::cout << "Gateway: " << pAdapterInfo->GatewayList.IpAddress.String << std::endl;
		std::cout << "Mac: " << hexStr(pAdapterInfo->Address, 6);
		
		std::cout << std::endl << std::endl;

		
		pAdapterInfo = pAdapterInfo->Next;
	}

	
}






