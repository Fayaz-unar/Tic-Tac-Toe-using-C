#include <stdio.h>

#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY ' '

char board[3][3]; 

void initializeBoard();
void printBoard();
int isBoardFull();
int checkWin(char player);
void playerMove(char player);

int main() {
    int gameOver = 0;
    int turnCount = 0;

    initializeBoard();

    while (!gameOver) {
        printBoard();
        if (turnCount % 2 == 0) {
            printf("Player X's turn\n");
            playerMove(PLAYER_X);
        } else {
            printf("Player O's turn\n");
            playerMove(PLAYER_O);
        }
        turnCount++;

        if (checkWin(PLAYER_X)) {
            printBoard();
            printf("Player X wins!\n");
            gameOver = 1;
        } else if (checkWin(PLAYER_O)) {
            printBoard();
            printf("Player O wins!\n");
            gameOver = 1;
        }

        if (isBoardFull() && !checkWin(PLAYER_X) && !checkWin(PLAYER_O)) {
            printBoard();
            printf("It's a draw!\n");
            gameOver = 1;
        }
    }

    return 0;
}

void initializeBoard() {
    	for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                return 0; 
            }
        }
    }
    return 1; 
}

int checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||  
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) { 
            return 1;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||  
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {  
        return 1;
    }

    return 0;  
}

void playerMove(char player) {
    int row, col;

    while (1) {
        printf("Enter row (1-3) and column (1-3) for player %c: ", player);
        scanf("%d %d", &row, &col);

        row--;
        col--;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == EMPTY) {
            board[row][col] = player;  
            break; 
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}
