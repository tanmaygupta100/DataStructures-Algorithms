/**
*File Name: proj3.cpp
*Academic Integrity Statement: I certify that, while others may have assisted me
in brain storming, debugging and validating this program, the program itself is
my own work. I understand that submitting code which is the work of other
individuals is a violation of the course Academic Integrity Policy and may
result in a zero credit for the assignment, or course failure and a report to
the Academic Dishonesty Board. I also understand that if I knowingly give my
original work to another individual that it could also result in a zero credit
for the assignment, or course failure and a report to the Academic Dishonesty
Board. See Academic Integrity Procedural GuidelinesLinks to an external site.
at:
https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelinesLinks
to an external site. *Assisted by and Assisted line numbers: *Your Name: Tanmay
Gupta *Your PSU user ID:  tqg5283 *CMPSC465 Semester 2023 *Due Time: 11:59PM,
Sunday, October 1, 2023 *Time of Last Modification: 5:00AM, Friday, October 6,
2023 *Description: This program takes in a board size and turns any O's
surrounded by X's into X's. To be considered 'surrounded', the O must have X's
surrounding it horizontally and vertically.
*/

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Function to find all the O's surrounded by X's,
 *  and recursively mark protected O's and their neighbors as visited.
 */
void scanRegion(vector<vector<char>> &board, int row, int col) {
  // Check if the current cell is out of bounds or not an O.
  if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
      board[row][col] != 'O')
    return;
  // What this checks:
  //  row < 0
  //  if row is less than 0 (above the board).
  // row >= board.size()
  // if row is greater than or equal to number of rows in the board (below the
  // board).
  // col < 0
  // if column is less than 0 (left of board).
  // col >= board[0].size()
  // if column is greater than or equal to number of columns in board (right of
  // board).
  // board[row][col] != 'O'
  // if current cell doesn't contain 0.

  // Temporarily mark the current cell as V to indicate it's visited.
  board[row][col] = 'V';
  // This is done to protect O's that aren't surrounded by X's.

  // Recursively check all neighboring cells of current cell
  scanRegion(board, row - 1,
             col); // Up (decrease "row" to check the cell above)
  scanRegion(board, row + 1,
             col); // Down (increase row to check the cell below)
  scanRegion(board, row,
             col - 1); // Left (decrease "col" to check the cell to the left)
  scanRegion(board, row,
             col + 1); // Right (increase col to check the cell to the right)
}

/**
 * Main method to open the file and mark the identified surrounded O's as X's.
 */
int main() {
  // Open the input file for reading:
  ifstream inputFile("board.txt");
  int n;          // variable to store first value read from the file.
  inputFile >> n; // Read the size of board (n), using extraction operator >>.

  // Create a 2D vector to store the board:
  vector<vector<char>> board(n, vector<char>(n));

  // Read the board from board.txt
  for (int i = 0; i < n; i++) // Reading the rows
  {
    for (int j = 0; j < n; j++) // Reading the columns
    {
      inputFile >> board[i][j]; // Add characters, X or O, into the board.
    }
  }

  inputFile.close(); // Close the input file.

  // Capture/Identify regions surrounded by X's starting from the border.
  for (int i = 0; i < n; i++) {
    // Check the left border/side of the board for O's:
    if (board[i][0] == 'O')        // 0 signifies the start (column 0)
      scanRegion(board, i, 0);     // Start identifying from the left side
    if (board[i][n - 1] == 'O')    // n-1 signifies the end (last column)
                                   // Check the right side of the board for O's:
      scanRegion(board, i, n - 1); // Start identifying from the right side
  }

  for (int j = 0; j < n; j++) {
    // Check the top side of the board for O's:
    if (board[0][j] == 'O')    // (row 0)
      scanRegion(board, 0, j); // Start identifying from the top border
    // Check the bottom side of the board for O's:
    if (board[n - 1][j] == 'O')    // (last row)
      scanRegion(board, n - 1, j); // Start identifying from the bottom border
  }

  // Convert O's to X's, and V's back to O's
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 'O')
        board[i][j] = 'X'; // Replace identified O's with X's.
      else if (board[i][j] == 'V')
        board[i][j] = 'O'; // Replace temporary V's with O's.
    }
  }

  // Print the resulting board
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << board[i][j] << " "; // Print each cell of the board.
    }
    cout << endl; // Move to the next row in the console output.
  }

  return 0;
}

/*
SAMPLE OUTPUT:
_________________
X X X X X O
X X X X X X
X X X X X X
X X X X X X
X X X X O O
X X X X X X
_________________
*/
