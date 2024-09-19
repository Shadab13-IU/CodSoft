#include <iostream>

using namespace std;

void drawBoard(char board[3][3]) {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player = 'X';

    while (true) {
        drawBoard(board);
        cout << "Player " << player << "'s turn. Enter row and column (1-3): ";
        int row, col;
        cin >> row >> col;
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "Invalid input. Please try again." << endl;
            continue;
        }
        if (board[row-1][col-1] != ' ') {
            cout << "Space already occupied. Please try again." << endl;
            continue;
        }

        board[row-1][col-1] = player;

        if (checkWin(board, player)) {
            drawBoard(board);
            cout << "Player " << player << " wins!" << endl;
            break;
        }

        if (checkDraw(board)) {
            drawBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}