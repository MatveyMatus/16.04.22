#include <iostream>
#include <fstream>
#include <ctime>

void write() {
    srand(time(NULL));
    std::ofstream RandomValue("input.txt");

    int column = rand() % 10 + 1;
    RandomValue << column;

    RandomValue.close();
}


int main()
{
    write();

    int column, mainLine = 0;

    std::ifstream Values("input.txt");
    Values >> column;
    Values.close();

    mainLine = (column * column + 1) / 2;

    std::ofstream result("output.txt");
    result << (mainLine - 1) / 9 * 10 + (mainLine - 1) % 9 + 1;
    result.close();
}
