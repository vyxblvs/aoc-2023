#include <iostream>
#include <fstream>
#include <string>

void part_1()
{
	std::ifstream file("c:\\input\\input.txt");
	std::string line;

	int sum = 0;

	while (std::getline(file, line))
	{
		int id = std::stoi(line.substr(line.find_first_of(' ') + 1));
		line.erase(0, line.find_first_of(':') + 2);
		line += ';';

		bool invalid_hand = false;
		while (true)
		{
			const size_t pos = line.find_first_of(';');
			std::string hand = line.substr(0, pos);

			while (!invalid_hand)
			{
				const int num = std::stoi(hand);
				size_t space_pos = hand.find_first_of(' ') + 1;

				switch (hand[space_pos])
				{
				case 'r': if (num > 12) invalid_hand = true; break;
				case 'g': if (num > 13) invalid_hand = true; break;
				case 'b': if (num > 14) invalid_hand = true;
				}

				space_pos = hand.find_first_of(' ', space_pos);
				if (space_pos == std::string::npos) break;
				else hand.erase(0, space_pos + 1);
			}
			if (invalid_hand) break;

			if (pos == line.length() - 1) break;
			else line.erase(0, line.find_first_of(';') + 2);
		}

		if (!invalid_hand) sum += id;
	}

	std::cout << "result: " << sum << '\n';
}