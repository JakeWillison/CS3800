#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <chrono>

using namespace std;

const int numOfElem = 25;
int numbers[numOfElem];
ofstream outputFile;

void sortArray(int numbers[]);

int main() {
    srand((unsigned int)time(NULL));
    outputFile.open("jmw_select2_out.txt", ios::app);
    
    //Set up array
    for (int i = 0; i < numOfElem; i++) {
        numbers[i] = 0;
    }

    auto start = chrono::high_resolution_clock::now();  //finds the time just before the sort begins
    
    //Fill array and sort array
    for (int i = 0; i < 25; i++) {
        int temp;
        temp = rand() % 1001;
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

    auto end = chrono::high_resolution_clock::now();    //finds the time just after the sort ends
    double exTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();    //this finds the execution time
    exTime *= 1e-9; //converts to seconds

    outputFile << "The largest number is " << numbers[0] << ": This took " << fixed << exTime << setprecision(9) << " seconds" << endl;

    return 0;
}