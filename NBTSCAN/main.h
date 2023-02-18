#pragma once
#include <stdio.h>
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <iphlpapi.h>
#include <stdlib.h>
#include <icmpapi.h>
#include <iostream>
#include <vector>

#include "target.h"
#include "headers.h"
#include "arp_request.h"
#include "adapter_scan.h"

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "iphlpapi.lib")

std::string get_name_from_ip(target* t);
int nbns_local_port(int adapter_idx, int octet);
//void nbns_request_packet(uint8_t** pkt, int* pkt_size);
std::string nbns_name_extraction(uint8_t* data);

void scan_adapter(adapter* ad);
DWORD WINAPI target_thread(void* data);
bool try_ping(std::string ip);