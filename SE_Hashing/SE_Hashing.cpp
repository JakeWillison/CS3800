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

    int collisionCount = 0;

    while (inFile >> currWord) {
        bool placed = false;
        
        //x = convert to ascii
        int i = 0; //this will be = x%5

        while (!placed) {
            if (hashTable[i] == "STOP") {
                hashTable[i] = currWord;
            }
            else {
                i++;
                collisionCount++;
            }
        }
    }

    inFile.close();
    return 0;
}