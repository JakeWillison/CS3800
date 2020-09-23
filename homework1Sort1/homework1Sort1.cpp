#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int numbers[25];

void sortArray(int numbers[]);

ifstream inFile;

int main() {
    int max;
    inFile.open("ints.txt");

    //Fill array

    for (int i = 0; i < 25; i++) {
        inFile >> numbers[i];
    }

    sortArray(numbers);
    cout << "The largest number is " << numbers[0] << endl;
}

void sortArray(int numbers[]) {
    int i = 0;
    while (i < 25) {
        for (int j = 1; j < 25; j++) {
            if (numbers[j] > numbers[j - 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j - 1];
                numbers[j - 1] = temp;
            }
        }
        i++;
    }
}
