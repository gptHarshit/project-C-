#include <iostream>
using namespace std;

char board[3][3];  // 3x3 game board
char currentPlayer;  // Tracks the current player

// Function to initialize the board with empty spaces
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '1' + (i * 3 + j);  // Board positions: '1' to '9'
        }
    }
    currentPlayer = 'X';  // X always starts the game
}

// Function to display the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Function to check if the current player has won
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;

    return false;
}

// Function to check if the game is a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;  // Empty space found, so it's not a draw
        }
    }
    return true;
}

// Function to switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to take player input and update the board
void playerMove() {
    int choice;
    bool validMove = false;

    do {
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> choice;

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = currentPlayer;
            validMove = true;
        } else {
            cout << "Invalid move. Try again.\n";
        }
    } while (!validMove);
}

int main() {
    char playAgain;
    do {
        initializeBoard();
        bool gameWon = false;
        bool gameDraw = false;

        cout << "Welcome to Tic-Tac-Toe!\n";
        displayBoard();

        // Game loop
        while (!gameWon && !gameDraw) {
            playerMove();
            displayBoard();
            gameWon = checkWin();
            gameDraw = checkDraw();

            if (gameWon) {
                cout << "Player " << currentPlayer << " wins! Congratulations!\n";
            } else if (gameDraw) {
                cout << "The game is a draw!\n";
            } else {
                switchPlayer();
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
