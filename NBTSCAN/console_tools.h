#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>
#include <sstream>

enum class console_color : uint16_t
{
	dark_blue = 1,
	dark_green = 2,
	dark_turqiouse = 3,
	dark_red = 4,
	dark_purple = 5,
	dark_yellow = 6,
	bright_grey = 7,
	dark_grey = 8,
	blue = 9,
	green = 10,
	turquoise = 11,
	red = 12,
	purple = 13,
	yellow = 14,
	white = 15
};

class console_tools
{
public:
	console_tools(bool verbose);

	void write_line();
	void write_line(int count);

	void write(std::string str);
	void write_line(std::string str);
	
	void write(std::string str, console_color color);
	void write_line(std::string str, console_color color);

	void write_property(std::string name, std::string value);

	void write_line_timestamp(std::string str);
	void write_line_timestamp(std::string str, console_color color);


	bool get_yes_no();
	

private:
	std::string now_timestamp();
	bool verbose;
	HANDLE console_handle;
	
};

