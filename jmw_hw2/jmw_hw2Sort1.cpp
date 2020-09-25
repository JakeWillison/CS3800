#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <stdlib.h> 
#include <ctime>
#include <chrono>

using namespace std;

const int numOfElem = 25;


void sortArray(int numbers[], int numOfElem);

ofstream outputFile;

int main() {
    srand((unsigned int)time(NULL));

 //   clock_t start, end;
    int numbers[numOfElem];

    outputFile.open("jmw_select_out.txt" , ios::app);


    //Fill array

    for (int i = 0; i < numOfElem; i++) {
        int rando = rand() % 1001;
        numbers[i] = rando;
    }

    auto start = chrono::high_resolution_clock::now();
//    start = clock();
    sortArray(numbers, numOfElem);
//    end = clock();
    auto end = chrono::high_resolution_clock::now();
    double exTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    exTime *= 1e-9;

    outputFile << "The largest number is " << numbers[0] << ": This took " << fixed << exTime << setprecision(9) << " seconds" << endl;
 

    outputFile.close();

    return 0;
}

void sortArray(int numbers[], int numOfElem) {
    int i = 0;
    while (i < numOfElem) {
        for (int j = 1; j < numOfElem; j++) {
            if (numbers[j] > numbers[j - 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j - 1];
                numbers[j - 1] = temp;
            }
        }
        i++;
    }
}