#pragma once
#include "found_host.h"
#include <vector>

class scan_result
{
public:
	found_host** found_matrix;
	std::vector<found_host*> found();

	static scan_result initialize(int count);
private:
	int count;

};

