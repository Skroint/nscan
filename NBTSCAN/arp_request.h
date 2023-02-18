#pragma once
#include <stdio.h>
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <iphlpapi.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "target.h"
#include <vector>
#include <sstream>
#include <iomanip>

int arp_request(target* target);