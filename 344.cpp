#include <iostream>
#include <fstream>
#include <ctime>

void write() {
    srand(time(NULL));
    std::ofstream RandomValue("input.txt");
    int quantity = rand() % 100 + 2;
    RandomValue << quantity << std::endl;
    for (int i = 0; i < quantity; ++i) {
        RandomValue << rand() % 1000 + 1 << " ";
    }

    RandomValue.close();
}

void sort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 2; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    write();

    int quantity,
        c = 0;

    std::ifstream inputValues("input.txt");
    inputValues >> quantity;
    int* Array = new int[quantity] {};
    int* ArrayOrigen = new int[quantity] {};

    for (int i = 0; i < quantity; ++i) {
        inputValues >> Array[i];
    }

    for (int i = 0; i < quantity; ++i) {
        ArrayOrigen[i] = Array[i];
    }

    inputValues.close();

    sort(Array, quantity);

    int item1 = 0,
        item2 = 0,
        minDist = 1000000000;

    for (int i = 1; i < quantity; ++i) {
        if (minDist > Array[i] - Array[i - 1] && Array[i] - Array[i - 1] >= 0) {
            minDist = Array[i] - Array[i - 1];
            item1 = Array[i - 1];
            item2 = Array[i];
        }
    }

    for (int i = 0; i < quantity; ++i) {
        if (ArrayOrigen[i] == item1) {
            item1 = i + 1;
        }
        else if (ArrayOrigen[i] == item2) {
            item2 = i + 1;
        }
    }

    std::ofstream result("output.txt");
    result << minDist << std::endl << item1 << " " << item2;

    result.close();
    delete[] Array;
    delete[] ArrayOrigen;
}
