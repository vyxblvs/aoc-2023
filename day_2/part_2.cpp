#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream file("c:\\input\\input.txt");
	std::string line;

	int sum = 0;

	while (std::getline(file, line))
	{
		int id = std::stoi(line.substr(line.find_first_of(' ') + 1));
		line.erase(0, line.find_first_of(':') + 2);
		line += ';';

		int r(0), g(0), b(0);
		while (true)
		{
			const size_t pos = line.find_first_of(';');
			std::string hand = line.substr(0, pos);

			while (true)
			{
				const int num = std::stoi(hand);
				size_t space_pos = hand.find_first_of(' ') + 1;

				switch (hand[space_pos])
				{
				case 'r': if (num > r) r = num; break;
				case 'g': if (num > g) g = num; break;
				case 'b': if (num > b) b = num;
				}

				space_pos = hand.find_first_of(' ', space_pos);
				if (space_pos == std::string::npos) break;
				else hand.erase(0, space_pos + 1);
			}

			if (pos == line.length() - 1) break;
			else line.erase(0, line.find_first_of(';') + 2);
		}

		sum += r * g * b;
	}

	std::cout << "result: " << sum << '\n';
	return 0;
}