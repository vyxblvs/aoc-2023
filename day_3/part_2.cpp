#include <iostream>
#include <fstream>
#include <string>


int main()
{
	std::ifstream file("c:\\input\\input.txt");
	std::string front_line, mid_line, back_line;
	int sum = 0;
	bool exit = false;

	file >> mid_line;
	while (!exit)
	{
		if (!(file >> front_line)) exit = true;

		for (int i = 0, pos = 0; i < std::count(mid_line.begin(), mid_line.end(), '*'); ++i)
		{
			int amount = 0;
			int numbers[2] = { 0, 0 };
			static std::string num;

			pos = mid_line.find_first_of('*', pos + 1);

			if (pos > 0 && std::isdigit(mid_line[pos - 1]))
			{
				std::reverse(mid_line.begin(), mid_line.end());

				num = std::to_string(std::stoi(mid_line.substr(mid_line.size() - pos)));

				std::reverse(mid_line.begin(), mid_line.end());
				std::reverse(num.begin(), num.end());

				numbers[0] = std::stoi(num);
				++amount;
			}

			if (pos < mid_line.size() - 1 && std::isdigit(mid_line[pos + 1]))
			{
				numbers[amount] = std::stoi(mid_line.substr(pos + 1));
				++amount;
			}

			for (char y = 0; y < 2; std::swap(back_line, front_line), ++y)
			{
				if (exit || front_line.empty()) continue;

				const int offset = pos - (pos > 0);
				num = front_line.substr(offset, 2 + (pos > 0));

				for (int z = 0; z < num.size(); ++z)
				{
					if (std::isdigit(num[z]))
					{
						static std::string num_2;
						int num_pos = z + offset;

						for (; num_pos >= 0; --num_pos)
						{
							const bool non_digit = std::isdigit(front_line[num_pos]) == 0;

							if (non_digit || !num_pos)
							{
								num_2 = std::to_string(std::stoi(front_line.substr(num_pos + non_digit)));
								break;
							}
						}

						
						if (!(pos < (z + offset) - (z + offset > 0)) && !(pos > z + offset + num_2.size()))
						{
							++amount;

							if (amount == 3)
							{
								y = 2;
								break;
							}

							numbers[amount - 1] = std::stoi(num_2);
						}

						if (!z && !std::isdigit(num[1])) ++z;
						else break;
					}
				}
			}

			if (amount == 2)
			{
				std::cout << numbers[0] << " - " << numbers[1] << '\n';
				sum += numbers[0] * numbers[1];
			}
		}

		back_line = mid_line;
		mid_line = front_line;
	}

	std::cout << "result: " << sum << '\n';
	return 0;
}