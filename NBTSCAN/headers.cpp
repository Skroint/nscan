#include "headers.h"

void get_nbns_request_packet(uint8_t** pkt, int* pkt_size)
{
	// Allocate packet memory
	*pkt_size = sizeof(nbns_header) + sizeof(nbns_request_header);
	*pkt = (uint8_t*)malloc(*pkt_size);

	// Header pointers
	nbns_header* nb = (nbns_header*)*pkt;
	nbns_request_header* re = (nbns_request_header*)(*pkt + sizeof(nbns_header));

	// NBNS header
	nb->transaction_id = 0x4701;
	nb->flags = 0x1000;
	nb->questions = 0x0100;
	nb->answer_rrs = 0x0000;
	nb->authority_rrs = 0x0000;
	nb->additional_rrs = 0x0000;

	// NBNS request header
	memset(re->name, 0x41, 34);
	re->name[0] = 0x20;
	re->name[1] = 0x43;
	re->name[2] = 0x4b;
	re->name[33] = 0x00;
	re->type = 0x2100;
	re->clss = 0x0100;
}