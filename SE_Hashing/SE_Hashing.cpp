#include <iostream>
#include <fstream>

using namespace std;

ifstream inFile;
ofstream outFile;

int main()
{
    inFile.open("hash.txt");
    
    const int arrLength = 17;
    string hashTable[arrLength];
    string currWord;

    for (int i = 0; i < arrLength; i++) {
        hashTable[i] = "STOP";
    }

    while (inFile >> currWord) {
        //convert to ascii
        //index = ascii % 5
        //if hasTable[index] == STOP
        // hashTable[index] = currWord;

    }

    inFile.close();
    return 0;
}