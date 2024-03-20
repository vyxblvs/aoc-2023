#include <iostream>
#include <fstream>
#include <string>

int part_1()
{
	std::ifstream file("c:\\input\\input.txt");
	std::string line, left;
	int sum = 0;

	while (std::getline(file, line))
	{
		line.erase(0, line.find_first_of(':') + 2);
		
		const size_t mid = line.find_first_of('|');
		left = line.substr(0, mid - 1);

		line.erase(0, mid + 1);
		line += ' ';

		int value = 0;
		
		for (int i = 0; i < left.size() - 1; i += 3)
		{
			const std::string num = ' ' + std::to_string(std::stoi(left.substr(i + (left[i] == ' ')))) + ' ';

			if (line.find(num) != std::string::npos)
			{
				if (!value) value = 1;
				else value *= 2;
			}
		}

		sum += value;
	}

	std::cout << "result: " << sum << '\n';
	return 0;
}