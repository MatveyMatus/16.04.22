#include <iostream>
#include <fstream>
#include <ctime>

void write() {
    srand(time(NULL));
    std::ofstream RandomValue("input.txt");
    int quantity = rand() % 100000 + 2;
    RandomValue << quantity << " ";
    for (int i = 0; i < quantity; ++i) {
        RandomValue << rand() % 2147483646 + 1 << " ";
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

    for (int i = 0; i < quantity; ++i) {
        inputValues >> Array[i];
    }

    inputValues.close();

    sort(Array, quantity);

    std::ofstream result("output.txt");
    if (Array[quantity - 1] == (Array[0] + (quantity - 1) * (Array[1] - Array[0]))) {
        result << "YES";
    }
    else {
        result << "NO";
    }
    result.close();
    delete[] Array;
}
