/**
*File Name: parenthesesCombinations.cpp
*Description: This program generates all combinations of given number of pairs of parentheses.
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * comboResults - Referencing a list to store generated combinations of parentheses.
 * currentCombo - String populated with current combination.
 * openPrnthsCount - Count of the open parentheses in CURRENT combination.
 * closedPrnthsCount - Count of the closed parentheses in CURRENT combination.
 * n - Number of pairs of parentheses to be given to create various unique combinations.
*/
void createParentheses(vector<string>& comboResults, string currentCombo,
                        int openPrnthsCount, int closedPrnthsCount, int n)
{
    //If current combo's length is valid, based on the standard calculated number of parentheses needed,
        // then add it to the stack.
    if(currentCombo.length() == 2 * n) // 2*n because there's n pairs, and 2 parentheses for each pair.
    {
        comboResults.push_back(currentCombo);
        return; // Exiting the function when a valid value is found.
            // Returns from the recursive call into a previous level of recursion.
            // AKA BACKTRACKING!
    }

    //Making sure we don't exceed allowed number of open parentheses:
        // STOPS after condition is no longer true.
        // Example: if n = 3, then OPC can still reach 3, not just 0,1, or 2,
        // but then fully stops the if-statment at 3.
    if(openPrnthsCount < n) // so if n = 3, and OPC = 3
    {
        createParentheses(comboResults, currentCombo + '(', openPrnthsCount + 1, closedPrnthsCount, n);
    }

    //Making sure we don't exceed allowed number of closed parentheses:
        // "closedPrnthsCount < openPrnthsCount" instead of "closedPrnthsCount < n" to match closed to open.
    if(closedPrnthsCount < openPrnthsCount) // so if n = 3, and CPC = 3
    {
        createParentheses(comboResults, currentCombo + ')', openPrnthsCount, closedPrnthsCount + 1, n);
    }
}


int main()
{
    int n;
    cout << "How many n pairs of parentheses are there? -> ";
    cin >> n;
    cout << "\nCombinations of " + to_string(n) + " pairs of parentheses: \n";
        // function 'to_string' converts n to a string for the printing function.

    //We want to print the combination results,
        // so we recreate the same variable to store the same values from the void method:
    vector<string> comboResults;
    createParentheses(comboResults, "", 0, 0, n);

    // Print each line of the combo results.
        // '&' is used to pass the string by reference instead of by each value. Meant for efficieny in memory/time.
    for(const string& s : comboResults)
    {
        cout << s << endl;
    }

    //Successful execution:
    return 0;
}

/*
Sample Output:
____________________________________________________
How many n pairs of parentheses are there? -> 3

Combinations of 3 pairs of parentheses: 
((()))
(()())
(())()
()(())
()()()
____________________________________________________
*/
