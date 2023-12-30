#include <iostream>
#include <string>
#include <codecvt>
#include <random>

using namespace std;

namespace LogGen
{
    char matrix[62] = {                                      // creating a matrix
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e',
        'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j',
        'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o',
        'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't',
        'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y',
        'Z', 'z'
    };

    int getRandomNumber(int min, int max) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> distribution(min, max);
        return distribution(gen);
    }

    string LogGenerate(int LogLen)
    {
        int Rnum;
        string str;
        for (int i = 0; i < LogLen; i++)
        {
            Rnum = getRandomNumber(0, 61);
            if (Rnum > 61) { Rnum = 61; }
            str += matrix[Rnum];
        }
        return str;
    }
};
