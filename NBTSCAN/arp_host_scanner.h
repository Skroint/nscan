#pragma once
#include "host_scanner.h"


class arp_host_scanner :
    public host_scanner
{
public:
    std::vector<std::string> scan(std::vector<std::string> targets) override;
    void scan(scan_result* sr, const std::vector<ipv4_address>& addresses) override;

};


//device_address device_address::from_addr_ptr(pcap_addr_t* addr_ptr,
//	pcap_if_t* dev_ptr)
//{
//	device_address address;
//
//	//	dev_ptr.
//
//		// Store npcap pointers
//	address.addr_ptr = addr_ptr;
//	address.dev_ptr = dev_ptr;
//
//	address.ip = ipv4_address::from_octets((uint8_t*)&addr_ptr->addr->sa_data[2]);
//	address.mask = ipv4_address::from_octets((uint8_t*)&addr_ptr->netmask->sa_data[2]);
//
//	address.device_name = std::string(dev_ptr->name);
//
//
//	return address;
//}
