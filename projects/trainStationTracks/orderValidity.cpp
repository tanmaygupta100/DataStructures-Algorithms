/**
*File Name: orderValidity.cpp
*Description: This program reads a text file and validates the lines of code to see if they are in a valid conceivable order if
they start at track A, move to the station, and can either be stacked in the station or move to track B.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <sstream>

using namespace std;

bool validityChecker(vector<int>& B, int N) // using & means you pass a reference of the original vector.
{
    stack<int> station;
    int currentCoach = 1; // initialized as 1 so we know to start from the first coach.
        // sequential order by starting at 1.

    // Do this loop for the entire size of numbers:
    for (int i = 0; i < N; ++i)
    {
        // Do this loop until station stack is empty:
        while (!station.empty())
        {
            station.pop(); // Removes top coach from station.
            ++currentCoach; // Moves onto the next coach after popping the current/previous coach.
        }

        // Check if current coach matches current location:
        if (B[i] == currentCoach)
        {
            ++currentCoach; // then move onto the next one.
        }
        // Check if station isn't empty AND not in sequential order.
        else if (!station.empty() && station.top() < B[i]) // IF coach at top is smaller than current incoming coach...
        {
            return false; // Invalid sequence
        }
        else
        {
            station.push(B[i]); // Push current coach to the station, making it the TOP coach!
        }
    }

    // If coach still isn't empty and the top coach matches current coach...
    while (!station.empty() && station.top() == currentCoach)
    {
        station.pop(); // Remove that top coach from stack (basically move it to the next track)
        ++currentCoach; // move onto the next coach.
    }

    return station.empty(); // returns true if station is empty, therefore the sequence was successful/valid.
}



int main()
{
    // Open and read text file:
    ifstream textFile("lab1in.txt");

    int N; // integer for number of coaches
    textFile >> N; //  read the first line in the file.
    //cout << N << endl; // for error checking.

    // Error checking:
    if(!textFile) // If file doesn't open properly.
    {
        cerr << "Error: Unable to open the input file\n";
        return 1; // return 0 is used for successful execution. return 1 is for errors.
        // ends the program.
    }
    if (N > 1000) // Number of values in blocks cannot pass 1000
    {
        cerr << "Error: N exceeds the limit of 1000.\n";
        return 1;
    }

    string line;
    getline(textFile, line); // Ignore the first line, since it is N and not a sequence.

    // Start reading each line and stop loop when no more lines:
    while (getline(textFile, line))
    {
        istringstream iss(line); //  converting the string to integers for the vector.
        int number;
        vector<int> B; // track B

        // Adds the lines strings of numbers as individual integers for each line in vector B.
        while (iss >> number)
        {
            B.push_back(number);
        }

        // Stop processing if the first number in the sequence is zero or if the sequence is empty.
        if (B.size() == 0 || B[0] == 0)
        {
            break;
        }

        // station.push(B); // Used this stack to store the sequences. Not needed for final program.

        // Commented out lines below are for error checking:
        /*for (int num : B)
        {
            cout << num << " ";
        }
        cout << endl;*/

        // Printing the results:
        if (validityChecker(B, B.size())) // Calling the method directly from the if-statement.
        {
            cout << "Yes" << endl;
        }
        else if (!validityChecker(B, B.size()))
        {
            cout << "No" << endl;
        }
    }

    textFile.close();
    return 0;
}

/*
Sample output:
_______________
No
Yes
No
No
No
Yes
Yes
_______________
*/
