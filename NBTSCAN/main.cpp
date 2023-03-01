/*
 * Copyright (c) 1999 - 2005 NetGroup, Politecnico di Torino (Italy)
 * Copyright (c) 2005 - 2006 CACE Technologies, Davis (California)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Politecnico di Torino, CACE Technologies
 * nor the names of its contributors may be used to endorse or promote
 * products derived from this software without specific prior written
 * permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifdef _MSC_VER
 /*
  * we do not want the warnings about the old deprecated and unsecure CRT functions
  * since these examples can be compiled under *nix as well
  */
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <pcap.h>
#include <stdio.h>
#include <string>
#include <winsock2.h>
#include <iostream>
#include "device_manager.h"
#include "console_tools.h"

bool load_npcap_dll()
{
	char npcap_dir[512];
	int len = GetSystemDirectory(npcap_dir, 480);
	std::string dir = std::string(npcap_dir);

	if (!len)
	{
		fprintf(stderr, "Error in GetSystemDirectory: %x", GetLastError());
		return FALSE;
	}
	
	dir += "\\Npcap";

	if (SetDllDirectory(dir.c_str()) == 0)
	{
		fprintf(stderr, "Error in SetDllDirectory: %x", GetLastError());
		return FALSE;
	}
	return TRUE;
}


int main()
{
	console_tools ct(true);
	if (!load_npcap_dll())
	{
		fprintf(stderr, "Couldn't load Npcap\n");
	}

	device_manager manager;
	manager.print_all_addresses();
	device_address device_address = manager.get_device_address();

	ct.write_line("Scanning");
	device_address.get_range().print();


	std::cin.get();
	std::cin.get();

	return 0;
}




//
//int main()
//{
//
//
//	return 0;
//	// Scan for adapters
//	std::vector<adapter*> adapters = scan_adapters();
//
//	// Get NBNS request packet and store it in a thread safe manner
//	get_nbns_request_packet(&nbns_request_packet, &nbns_request_packet_size);
//
//	// Iterate through all adapters and start scanning
//	for (int a = 0; a < adapters.size(); a++)
//	{
//		scan_adapter(adapters[a]);
//	}
//
//	// Wait
//	std::cout << "Scanning";
//	for (int s = 0; s < 70; s++)
//	{
//		Sleep(100);
//		std::cout << ".";
//	}
//	system("cls");
//
//
//	// Iterate through all adapters and print them
//	for (int a = 0; a < adapters.size(); a++)
//	{
//		adapters[a]->print_line();
//	}
//
//	// Prevent closing
//	std::cin.get();
//	std::cin.get();
//}
//
//void scan_adapter(adapter* ad)
//{
//	for (int t = 0; t < 255; t++)
//	{
//		HANDLE thread = CreateThread(NULL, 0, target_thread, &ad->targets[t], 0, NULL);
//	}
//}
//
//
//DWORD WINAPI target_thread(void* data)
//{
//	target* t = (target*)data;
//	arp_request(t);
//	if (t->found)
//	{
//		t->ping = try_ping(t->ip);
//		t->name = get_name_from_ip(t);
//	// name får inte vidare
//	}
//	return 0;
//}
//
////void nbns_request_packet(uint8_t** pkt, int* pkt_size)
////{
////	// Allocate packet memory
////	*pkt_size = sizeof(nbns_header) + sizeof(nbns_request_header);
////	*pkt = (uint8_t*)malloc(*pkt_size);
////
////	// Header pointers
////	nbns_header* nb = (nbns_header*)*pkt;
////	nbns_request_header* re = (nbns_request_header*)(*pkt + sizeof(nbns_header));
////
////	// NBNS header
////	nb->transaction_id = 0x4701;
////	nb->flags = 0x1000;
////	nb->questions = 0x0100;
////	nb->answer_rrs = 0x0000;
////	nb->authority_rrs = 0x0000;
////	nb->additional_rrs = 0x0000;
////
////	// NBNS request header
////	memset(re->name, 0x41, 34);
////	re->name[0] = 0x20;
////	re->name[1] = 0x43;
////	re->name[2] = 0x4b;
////	re->name[33] = 0x00;
////	re->type = 0x2100;
////	re->clss = 0x0100;
////}
////
//
//std::string get_name_from_ip(target* t)
//{
//	std::string name = "";
//	sockaddr_in dest;
//	sockaddr_in local;
//	WSAData data;
//	WSAStartup(MAKEWORD(2, 2), &data);
//
//	// Recieve
//	local.sin_family = AF_INET;
//	InetPton(AF_INET, t->adapter_ip.c_str(), &local.sin_addr.s_addr);
//	local.sin_port = nbns_local_port(t->adapter_idx, t->ip_octets[3]);
//
//	// Send
//	dest.sin_family = AF_INET;
//	InetPton(AF_INET, t->ip.c_str(), &dest.sin_addr.s_addr);
//	dest.sin_port = htons(137);
//	int slen = sizeof(dest);
//
//	// create the socket
//	SOCKET s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
//	// bind to the local address
//	bind(s, (sockaddr *)&local, sizeof(local));
//	// send the pkt
//	int ret = sendto(s, (char*)nbns_request_packet, nbns_request_packet_size, 0, (sockaddr*)&dest, sizeof(dest));
//
//	int recv_len = 0;
//	char buf[65000];
//
//	recv_len = recvfrom(s, buf, 65000, 0, (struct sockaddr*) &dest, &slen);
//
//	name = nbns_name_extraction((uint8_t*)buf);
//
//	return name;
//}
//
//bool try_ping(std::string ip)
//{
//
//	// Declare and initialize variables
//
//	HANDLE hIcmpFile;
//	unsigned long ipaddr = INADDR_NONE;
//	DWORD dwRetVal = 0;
//	char SendData[32] = "Data Buffer";
//	LPVOID ReplyBuffer = NULL;
//	DWORD ReplySize = 0;
//
//
//	InetPton(AF_INET, ip.c_str(), &ipaddr);
//	if (ipaddr == INADDR_NONE) 
//		return false;
//	
//	hIcmpFile = IcmpCreateFile();
//	if (hIcmpFile == INVALID_HANDLE_VALUE) 
//		return false;
//	
//	ReplySize = sizeof(ICMP_ECHO_REPLY) + sizeof(SendData);
//	ReplyBuffer = (VOID*)malloc(ReplySize);
//	
//	if (ReplyBuffer == NULL) 
//		return false;
//	
//
//
//	dwRetVal = IcmpSendEcho(hIcmpFile, ipaddr, SendData, sizeof(SendData),
//		NULL, ReplyBuffer, ReplySize, 1000);
//	if (dwRetVal != 0) 
//	{
//		/*PICMP_ECHO_REPLY pEchoReply = (PICMP_ECHO_REPLY)ReplyBuffer;
//		struct in_addr ReplyAddr;
//		ReplyAddr.S_un.S_addr = pEchoReply->Address;
//		printf("\tSent icmp message to\n");
//		if (dwRetVal > 1) {
//			printf("\tReceived %ld icmp message responses\n", dwRetVal);
//			printf("\tInformation from the first response:\n");
//		}
//		else {
//			printf("\tReceived %ld icmp message response\n", dwRetVal);
//			printf("\tInformation from this response:\n");
//		}
//		printf("\t  Received from\n");
//		printf("\t  Status = %ld\n",
//			pEchoReply->Status);
//		printf("\t  Roundtrip time = %ld milliseconds\n",
//			pEchoReply->RoundTripTime);*/
//	}
//	else
//	{
//		return false;
//	}
//	return true;
//}
//
////bool try_ping(std::string ip)
////{
////
////	// Declare and initialize variables
////
////	HANDLE hIcmpFile;
////	unsigned long ipaddr = INADDR_NONE;
////	DWORD dwRetVal = 0;
////	char SendData[32] = "Data Buffer";
////	LPVOID ReplyBuffer = NULL;
////	DWORD ReplySize = 0;
////
////
////	InetPton(AF_INET, ip.c_str(), &ipaddr);
////	if (ipaddr == INADDR_NONE) {
////		printf("usage: %s IP address\n");
////		return 1;
////	}
////
////	hIcmpFile = IcmpCreateFile();
////	if (hIcmpFile == INVALID_HANDLE_VALUE) {
////		printf("\tUnable to open handle.\n");
////		printf("IcmpCreatefile returned error: %ld\n", GetLastError());
////		return 1;
////	}
////
////	ReplySize = sizeof(ICMP_ECHO_REPLY) + sizeof(SendData);
////	ReplyBuffer = (VOID*)malloc(ReplySize);
////	if (ReplyBuffer == NULL) {
////		printf("\tUnable to allocate memory\n");
////		return 1;
////	}
////
////
////	dwRetVal = IcmpSendEcho(hIcmpFile, ipaddr, SendData, sizeof(SendData),
////		NULL, ReplyBuffer, ReplySize, 1000);
////	if (dwRetVal != 0) {
////		PICMP_ECHO_REPLY pEchoReply = (PICMP_ECHO_REPLY)ReplyBuffer;
////		struct in_addr ReplyAddr;
////		ReplyAddr.S_un.S_addr = pEchoReply->Address;
////		printf("\tSent icmp message to\n");
////		if (dwRetVal > 1) {
////			printf("\tReceived %ld icmp message responses\n", dwRetVal);
////			printf("\tInformation from the first response:\n");
////		}
////		else {
////			printf("\tReceived %ld icmp message response\n", dwRetVal);
////			printf("\tInformation from this response:\n");
////		}
////		printf("\t  Received from\n");
////		printf("\t  Status = %ld\n",
////			pEchoReply->Status);
////		printf("\t  Roundtrip time = %ld milliseconds\n",
////			pEchoReply->RoundTripTime);
////	}
////	else {
////		printf("\tCall to IcmpSendEcho failed.\n");
////		printf("\tIcmpSendEcho returned error: %ld\n", GetLastError());
////		return 1;
////	}
////	return 0;
////}
//
//int nbns_local_port(int adapter_idx, int octet)
//{
//	return (adapter_idx + 3) * 1000 + octet;
//}
//
//std::string nbns_name_extraction(uint8_t* data)
//{
//	nbns_header* nb = (nbns_header*)data;
//	nbns_answer_name* na = (nbns_answer_name*)(data + sizeof(nbns_header) + NBNS_ANSWER_HEADER_SIZE);
//
//	return std::string((char*)na->name);
//}
//
//

