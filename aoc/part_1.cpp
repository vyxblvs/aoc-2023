#include <iostream>
#include <fstream>
#include <string>

void part_1()
{
	std::ifstream file("c:\\input\\input.txt");
	std::string line;

	int sum = 0;

	while (file >> line)
	{
		static std::string number;

		for (int i = 0; i < line.length(); ++i)
		{
			if (std::isdigit(line[i]))
			{
				number += line[i];
				i = -1;
				std::reverse(line.begin(), line.end());
			}

			if (number.size() == 2)
			{
				sum += std::stoi(number);
				number.clear();
				break;
			}
		}
	}

	std::cout << "result: " << sum << '\n';
}