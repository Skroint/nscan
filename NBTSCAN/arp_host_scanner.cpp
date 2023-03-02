#include "arp_host_scanner.h"
#include <pcap.h>

std::vector<std::string> arp_host_scanner::scan(std::vector<std::string> targets)
{
	

    return std::vector<std::string>();
}

void arp_host_scanner::scan(scan_result* sr, const std::vector<ipv4_address>& addresses)
{
	pcap_if_t* devices;

	char error_buffer[PCAP_ERRBUF_SIZE + 1];

	if (pcap_findalldevs(&devices, error_buffer) == -1)
	{
		fprintf(stderr, "Error in pcap_findalldevs: %s\n", error_buffer);
	}

	for (pcap_if_t* d = devices; d; d = d->next)
	{

	}




}
