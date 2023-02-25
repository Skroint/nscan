#include "console_tools.h"

/// <summary>
/// Initializes a new instance of <see cref="console_tools"/>
/// </summary>
/// <param name="muted"></param>
console_tools::console_tools(bool verbose)
{
	this->verbose = verbose;
	console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
}

/// <summary>
/// Write a single thing to console without line break
/// </summary>
void console_tools::write(std::string str)
{
	write(str, console_color::white);
}

/// <summary>
/// Write a single thing to console with line break
/// </summary>
/// <param name="str"></param>
void console_tools::write_line(std::string str)
{
	write_line(str, console_color::white);
}

/// <summary>
/// Write an empty line
/// </summary>
void console_tools::write_line()
{
	write_line("");
}

/// <summary>
/// Write N count empty lines
/// </summary>
void console_tools::write_line(int count)
{
	for (int i = 0; i < count; i++)
	{
		write_line();
	}
}

/// <summary>
/// Write to console with color
/// </summary>
void console_tools::write(std::string str,
	console_color color)
{
	if (verbose)
	{
		SetConsoleTextAttribute(console_handle, (uint16_t)color);
		std::cout << str;
	}
}

/// <summary>
/// Write line to console with specified color
/// </summary>
void console_tools::write_line(std::string str,
	console_color color)
{
	if (verbose)
	{
		SetConsoleTextAttribute(console_handle, (uint16_t)color);
		std::cout << str << std::endl;
	}
}

/// <summary>
/// Write a property to console
/// </summary>
void console_tools::write_property(std::string name,
	std::string value)
{
	write("[" + name + "] ", console_color::dark_grey);
	write_line(value, console_color::white);
}


/// <summary>
/// Write a message with a timestamp
/// </summary>
void console_tools::write_line_timestamp(std::string str)
{
	write_line_timestamp(str, console_color::white);
}

/// <summary>
/// Write a message with a timestamp
/// </summary>
void console_tools::write_line_timestamp(std::string str,
	console_color color)
{
	if (verbose)
	{
		// Write timestamp
		SetConsoleTextAttribute(console_handle, (uint16_t)console_color::dark_grey);
		std::cout << "[" << now_timestamp() << "] ";

		// Write the message
		write_line(str, color);
	}
}

/// <summary>
/// Get yes/no input from user
/// </summary>
/// <returns></returns>
bool console_tools::get_yes_no()
{

	while (true)
	{
		SetConsoleTextAttribute(console_handle, (uint16_t)console_color::dark_grey);
		std::cout << ">";

		SetConsoleTextAttribute(console_handle, (uint16_t)console_color::white);
		std::string response = "";
		std::cin >> response;

		// Yes!
		if (response == "Y" ||
			response == "y")
		{
			return true;
		}

		// No!
		if (response == "N" ||
			response == "n")
		{
			return false;
		}
	}
}

/// <summary>
/// Get timestamp as this very moment
/// </summary>
/// <returns></returns>
std::string console_tools::now_timestamp()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);

	std::stringstream ss;

	// Hours
	if (newtime.tm_hour < 10)
	{
		ss << "0";
	}
	ss << newtime.tm_hour << ":";

	// Minutes
	if (newtime.tm_min < 10)
	{
		ss << "0";
	}
	ss << newtime.tm_min << ":";

	// Seconds
	if (newtime.tm_sec < 10)
	{
		ss << "0";
	}
	ss << newtime.tm_sec;

	return ss.str();
}

