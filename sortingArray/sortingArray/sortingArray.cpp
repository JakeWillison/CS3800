#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

ifstream inFile;
ofstream outFile;

int main()
{
    inFile.open("sortedInts.txt");              //accesses  sortedInts
    outFile.open("jmw_output.txt", ios::app);   //opens output and sets to append

    const int arrayLength = 200;                //variables
    int arr[arrayLength];
    int currNum;
    int index = 0;
    int num;
    bool found = false;
    int numOfComp = 0;

    while (inFile >> currNum) {                 //establishes array
        arr[index] = currNum;
        index++;
    }

    cout << "Enter number to search for " << endl;  //target
    cin >> num;

    //binary search
    int front = 0;
    int back = arrayLength;
    int mid;

    while (!found && front+1 != back) {
        numOfComp++;        //for !found
        numOfComp++;        //for front+2 != back;

        mid = (front + back) / 2;

        if (num == arr[mid]) {      //check if the number is found
            found = true;
            numOfComp++;
        }
        else if (num < arr[mid]) {  //resets the search for <
            back = mid;
            numOfComp++;
        }
        else {                      //resets the search for >
            front = mid;
        }

    }

    if (found)                      //output for found
        outFile << "The number " << num << " was found with " << numOfComp << " comparisons." << endl;

    else {                          //output for !found
        outFile << "The number " << num << " was NOT found. It took " << numOfComp << " comparisons." << endl;
    }
    
    inFile.close();                 //closing statements
    outFile.close();
    return 0;
}
