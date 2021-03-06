#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <streambuf>

//
void replaceAll(std::string & str, const std::string & from, const std::string & to) {
	if (from.empty())
		return;
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
	}
}

//
int main(int argc, char ** argv)
{
	if (argc != 4)
	{
		std::cout << "invalid arguments" << std::endl;
		return -1;
	}

	std::string path = argv[1];
	std::string src = argv[2];
	std::string dst = argv[3];

	std::ifstream file(path.c_str());

	std::stringstream buffer;
	buffer << file.rdbuf();

	std::string content = buffer.str();
	replaceAll(content, src, dst);

	std::cout << content << std::endl;

	return 0;
}