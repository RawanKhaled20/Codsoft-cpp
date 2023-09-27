/* Author: Rawan Khaled https://github.com/RawanKhaled20/Codsoft-cpp.git*/

#include <iostream>
#include <unistd.h>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "___________" << endl;
        cout<<endl;
    }
}

// Function to check if the current player has won
bool checkWin(char board[3][3], char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false; // There is an empty cell, the game is not a draw
        }
    }
    return true; // All cells are filled, the game is a draw
}

int main() {
    bool Try_again=true;

    while (Try_again)
    { cout<<endl;
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; // Initialize an empty 3x3 board
    char currentPlayer = 'X';
    bool gameFinished = false;

    string text="Tic-Tac-Toe!";
      for (char letter : text) {
        cout << letter;
        cout.flush(); // Flush the output buffer to display the character immediately
        usleep(50000);; // Sleep for 1 second between letters
    }
    cout<<endl<<endl;

    while (!gameFinished) {
        // Display the current state of the board
        displayBoard(board);

        // Prompt the current player to enter their move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): "<<endl;
        cin >> row >> col;
        cout<<endl;

        // Check if the move is valid
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            // Update the board with the player's move
            board[row][col] = currentPlayer;

            // Check if the current player has won
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameFinished = true;
            }
            // Check if the game is a draw
            else if (checkDraw(board)) {
                displayBoard(board);
                cout <<"It's a draw!" << endl;
                gameFinished = true;
            }
            // Switch to the other player
            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                cout<<"ongoing"<<endl<<endl;
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    cout << "Thanks for playing!, Type 1 to play another round " << endl;
    int tryagain;
    cin>>tryagain;

    if (tryagain != 1)
    {
        Try_again=false;
    }
    }

    return 0;
}

