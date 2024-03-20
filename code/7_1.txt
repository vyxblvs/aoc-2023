#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


struct ch_density
{
    char ch;
    const short instances;
};


char CnvChar(char ch)
{
    if (ch == 'J') ch = 83;
    else if (std::isdigit(ch)) ch = (10 - (ch - 48)) + 85;
    return ch;
}

std::vector<ch_density> GetChars(std::string hand)
{
    std::vector<ch_density> chars;

    while (hand.length())
    {
        const char ch = hand[0];
        chars.emplace_back(ch_density{ ch, static_cast<short>(std::count(hand.begin(), hand.end(), ch)) });
        hand.erase(std::remove(hand.begin(), hand.end(), ch), hand.end());
    }

    ch_density level = { 0, 0 };
    for (short x = 0; x < chars.size(); ++x)
    {
        if (chars[x].instances > level.instances) memcpy(&level, &chars[x], sizeof(ch_density));
    }
    chars.emplace_back(level);

    return chars;
}

bool IsCardBetter(const std::string& card_1, const std::string& card_2)
{
    const std::vector<ch_density> chars[2] = { GetChars(card_1), GetChars(card_2) };

    if (chars[0].back().instances != chars[1].back().instances) return chars[0].back().instances > chars[1].back().instances;
    else
    {
        for (short x = 0; x < 5; ++x)
        {
            if (card_1[x] != card_2[x])
            {
                return CnvChar(card_1[x]) < CnvChar(card_2[x]);
            }
        }
    }
}

int main()
{
    std::string line(MAX_PATH, NULL);
    GetModuleFileNameA(nullptr, line.data(), MAX_PATH);

    std::ifstream input((line.substr(0, line.find_last_of('\\') + 1)) + "input.txt");
    line.clear();
    std::vector<std::string> hands;

    while (std::getline(input, line))
    {
        int pos = 0;
        for (;pos < hands.size(); ++pos)
        {
            if (!IsCardBetter(line.substr(0, line.find_first_of(' ')), hands[pos].substr(0, hands[pos].find_first_of(' '))))
                break;
        }
        hands.insert(hands.begin() + pos, line);
    }

    int sum = 0;
    for (int x = 0; x < hands.size(); ++x)
    {
        const int number = std::stoi(hands[x].substr(hands[x].find_first_of(' ')));
        sum += number * (x + 1);
    }
    
    std::cout << "result: " << sum << '\n';
    return true;
}