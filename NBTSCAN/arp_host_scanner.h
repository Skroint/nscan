#pragma once
#include "host_scanner.h"


class arp_host_scanner :
    public host_scanner
{
public:
    std::vector<std::string> scan(std::vector<std::string> targets) override;
};

