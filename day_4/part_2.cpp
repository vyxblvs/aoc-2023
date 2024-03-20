#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	std::ifstream file("c:\\input\\input.txt");
	std::string line, left;
	int sum = 0;

	std::vector<int> copies(11);
	std::fill(copies.begin(), copies.end(), 0);

	while (std::getline(file, line))
	{
		++sum;

		line.erase(0, line.find_first_of(':') + 2);

		const size_t mid = line.find_first_of('|');
		left = line.substr(0, mid - 1);

		line.erase(0, mid + 1);
		line += ' ';

		int card = 0;

		for (int i = 0; i < left.size() - 1; i += 3)
		{
			const std::string num = ' ' + std::to_string(std::stoi(left.substr(i + (left[i] == ' ')))) + ' ';

			if (line.find(num) != std::string::npos)
			{
				++card;
				const int amount = 1 + copies[0];
				sum += amount;
				copies[card] += amount;
			}
		}

		copies.erase(copies.begin(), copies.begin() + 1);
		copies.emplace_back(0);
	}

	std::cout << "result: " << sum << '\n';
	return 0;
}