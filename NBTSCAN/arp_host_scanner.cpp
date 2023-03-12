#include "arp_host_scanner.h"
#include <pcap.h>



void arp_host_scanner::scan(scan_result* sr, 
	const std::vector<ipv4_address>& addresses,
	const device_address da)
{
	pcap_if_t* devices;

	char error_buffer[PCAP_ERRBUF_SIZE + 1];

	if (pcap_findalldevs(&devices, error_buffer) == -1)
	{
		fprintf(stderr, "Error in pcap_findalldevs: %s\n", error_buffer);
	}

	pcap_if_t* pcap_device = nullptr;
	pcap_addr_t* pcap_address = nullptr;

	for (pcap_if_t* d = devices; d; d = d->next)
	{
		for (pcap_addr_t* a = d->addresses; a; a = a->next)
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
				ipv4_address ip = ipv4_address::from_octets((uint8_t*)&a->addr->sa_data[2]);

				if (ip.to_string() == "")
				{

				}
			}
		}
	}




}
