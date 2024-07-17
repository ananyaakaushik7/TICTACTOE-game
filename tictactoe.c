#include <stdio.h>

// Tic Tac Toe game
void printBoard(char board[4][4]) {
    printf("\nTic Tac Toe Board:\n");
    printf("------------------\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n------------------\n");
    }
    printf("\n");
}

// Check if a player has won
int checkWin(char board[4][4], char player) {
    for (int i = 0; i < 4; i++) {
        
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player && board[i][3] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player && board[3][i] == player)) {
            return 1; 
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player && board[3][3] == player) ||
        (board[0][3] == player && board[1][2] == player && board[2][1] == player && board[3][0] == player)) {
        return 1; 
    }

    return 0; 
}

// Check if the game is tie
int checkTie(char board[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == ' ')
                return 0; 
        }
    }
    return 1; 
}

// Reset the game to original state
void resetBoard(char board[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = ' ';
        }
    }
}

int main() {
    char board[4][4];
    int row, col;
    char currentPlayer = 'X';

    // Initialize the board
    resetBoard(board);

    printf("Welcome to Tic Tac Toe!\n");

    do {
        // Print the present state of the game
        printBoard(board);

        
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

       
        if (row < 0 || row >= 4 || col < 0 || col >= 4 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        // Check for a tie
        if (checkTie(board)) {
            printBoard(board);
            printf("No one wins. It's a tie!\n");
            break;
        }

        // Switch to other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    } while (1); // Let the loop run infinitely for the rest of the game

    return 0;
}

