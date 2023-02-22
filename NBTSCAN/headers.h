//#pragma once
//#include <stdint.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//// Byte order reversed
//
//#define IPV4_TYPE			0x0008
//#define ARP_TYPE			0x0608
//
//#define TCP_PROTOCOL		0x06
//#define UDP_PROTOCOL		0x11
//
//#define ARP_REPLY			0x0200
//#define ARP_REQUEST			0x0100
//
//#define ICMP_PROTOCOL		0x01
//#define ICMP_REQUEST		0x08
//#define ICMP_REPLY			0x00
//
//#define TCP_RST_FLAG		0x1450
//#define TCP_SYN_FLAG		0x0280
//
//#define NBNS_RESPONSE_FLAG	0x0084
//#define NBNS_QUERY_FLAG		0x1000
//
//#define NBNS_ANSWER_HEADER_SIZE	45
//#define NBNS_NON_IDX			98
//
//
//void get_nbns_request_packet(uint8_t** pkt, int* pkt_size);
//
////typedef struct _ethernetHeader
////{
////	uint8_t DestinationMAC[6];
////	uint8_t SourceMAC[6];
////	uint16_t ProtocolType;
////}EthernetHeader;
//
////typedef struct _arpHeader
////{
////	uint16_t HardwareType;
////	uint16_t ProtocolType;
////	uint8_t HardwareSize;
////	uint8_t ProtocolSize;
////	uint16_t OpCode;
////	uint8_t SenderMAC[6];
////	uint8_t SenderIP[4];
////	uint8_t TargetMAC[6];
////	uint8_t TargetIP[4];
////}ARPHeader;
//
////typedef struct _ipv4Header
////{
////	uint8_t VersionHL;
////	uint8_t TypeOfServices;
////	uint16_t TotalLength;
////	uint16_t Identification;
////	uint16_t FlagsFO;
////	uint8_t TimeToLive;
////	uint8_t Protocol;
////	uint16_t HeaderChecksum;
////	uint8_t SenderIP[4];
////	uint8_t TargetIP[4];
////}IPV4Header;
//
//typedef struct _icmpHeader
//{
//	uint8_t Type;
//	uint8_t Code;
//	uint16_t CheckSum;
//	uint16_t IdentifierBE;
//	uint16_t IdentifierLE;
//	uint16_t SeqNumberBE;
//	uint16_t SeqNumberLE;
//	uint8_t Data[32];
//}ICMPHeader;
//
//
////typedef struct _tcpHeader
////{
////	uint16_t SourcePort;
////	uint16_t DestinationPort;
////	uint32_t SequenceNumber;
////	uint32_t AcknowledgementNumber;
////	uint16_t HLFlags;
////	uint16_t WindowSizeValue;
////	uint16_t Checksum;
////	uint16_t UrgentPointer;
////}TCPHeader;
//
////typedef struct _udpHeader
////{
////	uint16_t SourcePort;
////	uint16_t DestinationPort;
////	uint16_t Length;
////	uint16_t Checksum;
////}UDPHeader;
//
//
//typedef struct _nbns_header
//{
//	uint16_t transaction_id;
//	uint16_t flags;
//	uint16_t questions;
//	uint16_t answer_rrs;
//	uint16_t authority_rrs;
//	uint16_t additional_rrs;
//}nbns_header;
//
////typedef struct _nbnsHeader
////{
////	uint16_t TransacID;
////	uint16_t Flags;
////	uint16_t Questions;
////	uint16_t AnswerRRs;
////	uint16_t AuthorityRRs;
////	uint16_t AdditionalRRs;
////}NBNSHeader;
//
//#define NBNS_ANSWER_HEADER_SIZE	45
//typedef struct _nbnsAnswerHeader
//{
//	uint8_t name[34];
//	uint16_t type;
//	uint16_t cls;
//	uint32_t time_to_live;
//	uint16_t data_length;
//	uint32_t number_of_names;
//	//uint8_t Padding[3];
//}NBNSAnswerHeader;
//
//typedef struct _nbns_request_header
//{
//	uint8_t name[34];
//	uint16_t type;
//	uint16_t clss;
//}nbns_request_header;
//
//typedef struct _nbns_answer_name
//{
//	uint8_t name[16];
//	uint16_t flags;
//}nbns_answer_name;
//
//
//
