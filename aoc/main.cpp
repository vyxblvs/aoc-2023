#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream file("c:\\input\\input.txt");
	std::string line(255, 0);

	while (file.getline(line.data(), 255))
	{

	}

	return 0;
}