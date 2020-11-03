#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

ifstream inFile;

//Same functions as the other, with exception of different hashing function

int convertToASCII(string letter)
{
    int totalASCII = 0;
	
    for (int i = 0; i < letter.length(); i++)
    {
        char x = letter.at(i);
        totalASCII += int(x);
    }

	return totalASCII;
}

int main()
{
    inFile.open("hash.txt");
    
    const int arrLength = 23;
    string hashTable[arrLength];
    string currWord;




    for (int i = 0; i < arrLength; i++) {
        hashTable[i] = "STOP";
    }

    int collisionCount = 0;

    while (inFile >> currWord) {
        bool placed = false;
        

	int stringValue = convertToASCII(currWord);

	int i = (2*stringValue)%5; //Hashing Function	

        while (!placed) {
            if (hashTable[i] == "STOP") {
                hashTable[i] = currWord;
		placed = true;
            }
            else {
                i++;

		if(i > (arrLength - 1))
		{
			i = 0;
		}

                collisionCount++;
            }
        }
    }

	cout << "Number of Collisions: " << collisionCount << endl;
	
	cout << "Contents of the Hash Table: " << endl; 
	
	for(string x: hashTable)
	{
		cout << x << endl;
	}

    inFile.close();
    return 0;
}


