#include <iostream>
#include <fstream>
#include <string>


int part_1()
{
	std::ifstream file("c:\\input\\input.txt");
	std::string front_line, back_line;
	int sum = 0;
	bool exit = false;

	file >> back_line;
	while (!exit)
	{
		if (!(file >> front_line)) exit = true;

		for (char x = 0; x < 2 - exit; std::swap(back_line, front_line), ++x)
		{
			for (int pos = 0; pos < back_line.size(); ++pos)
			{
				if (std::isdigit(back_line[pos]))
				{
					static std::string num;
					num = std::to_string(std::stoi(back_line.substr(pos)));

					if (x == 0 &&
						((pos > 0 && back_line[pos - 1] != '.') ||
							(pos + num.size() < back_line.size() && back_line[pos + num.size()] != '.')))
					{
						sum += std::stoi(num);
					}

					else if (!exit)
					{
						static std::string below;
						below = front_line.substr(pos > 0 ? pos - 1 : 0, num.size() + 1 + (pos > 0));

						for (char y = 0; y < below.size(); ++y)
						{
							if (below[y] != '.' && !std::isdigit(below[y]))
							{
								sum += std::stoi(num);
								break;
							}
						}
					}

					pos += num.size() - 1;
				}
			}
		}

		back_line = front_line;
	}

	std::cout << "result: " << sum << '\n';
	return 0;
}