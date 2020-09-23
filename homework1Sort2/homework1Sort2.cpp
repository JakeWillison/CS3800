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

    //Set up array

    for (int i = 0; i < 25; i++) {
        numbers[i] = 0;
    }

    //Fill array

    for (int i = 0; i < 25; i++) {
        int temp;
        inFile >> temp;
        int j = 0;
        while (j <= i) {
            if (numbers[j] < temp) {
                int replace = numbers[j];
                numbers[j] = temp;
                temp = replace;
            }
            j++;
        }

    }


    cout << "The largest number is " << numbers[0] << endl;

}