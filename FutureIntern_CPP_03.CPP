#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void displayBoard() {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }
    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

void computerMove() {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' '); // Keep trying until an empty spot is found
    board[row][col] = 'O'; // Assume computer uses 'O'
    cout << "Computer chose: " << row << " " << col << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    char player = 'X'; // Player uses 'X'
    
    while (true) {
        displayBoard();
        // Player's turn
        int row, col;
        cout << "Player " << player << ", enter your move (row and column): ";
        cin >> row >> col;

        if (board[row][col] == ' ') {
            board[row][col] = player;

            if (checkWin(player)) {
                displayBoard();
                cout << "Player " << player << " wins!" << endl;
                break;
            } else if (isDraw()) {
                displayBoard();
                cout << "It's a draw!" << endl;
                break;
            }

            // Computer's turn
            computerMove();

            if (checkWin('O')) {
                displayBoard();
                cout << "Computer wins!" << endl;
                break;
            } else if (isDraw()) {
                displayBoard();
                cout << "It's a draw!" << endl;
                break;
            }
        } else {
            cout << "Invalid move! Try again." << endl;
        }
    }
    return 0;
}
