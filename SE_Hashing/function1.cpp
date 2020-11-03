#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

ifstream inFile;

//Assignment by Nathan Islam, De'Aundre Snow, Jake Willison

int convertToASCII(string letter) //Function to convert the string/words into ASCII
{
    int totalASCII = 0;
	
    for (int i = 0; i < letter.length(); i++) //FOR Loop for each character in the current word
    {
        char x = letter.at(i);
        totalASCII += int(x); //Creates running total for the word, so that hashed into the table
    }

	return totalASCII;
}

int main()
{
    inFile.open("hash.txt");
    
    const int arrLength = 17;
    string hashTable[arrLength];
    string currWord;

    for (int i = 0; i < arrLength; i++) //Creates the hash table, filling with "STOPS"
    {
        hashTable[i] = "STOP";
    }

    int collisionCount = 0;

    while (inFile >> currWord) { //Passes in the strings from the text file
        bool placed = false;
        
	int stringValue = convertToASCII(currWord);

	int i = stringValue%5;	//Hashing Function

        while (!placed) { 			//Checks for collisions and if they should move to the next spot in the table or not
            if (hashTable[i] == "STOP") {
                hashTable[i] = currWord;
		placed = true;
            }
            else {
                i++;
		
		if (i > (arrLength - 1)) //Condition for if the value would need to move back to the top of the table.
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


