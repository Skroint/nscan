#pragma once
#include "host_scanner.h"

class tcp_host_scanner :
    public host_scanner
{
public:
    virtual std::vector<std::string> scan(std::vector<std::string> targets) override;
};

