#include <iostream>
#include <fstream>
#include <string>

int main()
{
	constexpr const char* numbers[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	std::ifstream file("c:\\input\\input.txt");
	std::string line;

	int sum = 0;
	
	while (file >> line)
	{
		static std::string number;
		
		for (int i = 0, x = 1; i < line.length(); i += x)
		{
			if (std::isdigit(line[i]))
			{
				number += line[i];
				i = line.length();
				x = -1;
			}

			else
			{
				for (int y = 0; y < sizeof(numbers) / sizeof(const char*); ++y)
				{
					if (strcmp(line.substr(i, strlen(numbers[y])).c_str(), numbers[y]) == 0)
					{
						number += std::to_string(y + 1);

						if (x != -1)
						{
							x = -1;
							i = line.length();
						}

						break;
					}
				}
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

	return 0;
}