#include <string>
#include <vector>

using namespace std;

int count(vector<string>& board, char c) {
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == c) cnt++;
        }
    }
    return cnt;
}

int checkWin(vector<string>& board, char c) {
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c) cnt++;
        if (board[0][i] == c && board[1][i] == c && board[2][i] == c) cnt++;
    }
    if (board[0][0] == c && board[1][1] == c && board[2][2] == c) cnt++;
    if (board[2][0] == c && board[1][1] == c && board[0][2] == c) cnt++;
    return cnt;
}

int solution(vector<string> board) {
    int winO = checkWin(board, 'O');
    int winX = checkWin(board, 'X');
    if (winO > 2 || winX > 1 || (winO && winX)) return 0;
    int cntO = count(board, 'O');
    int cntX = count(board, 'X');
    if (cntO < cntX || cntO > 5 || cntX > 4) return 0;
    else if (winO == winX && !(cntO == cntX || cntO == cntX + 1)) return 0;
    else if (winO && !(cntO == cntX + 1)) return 0;
    else if (winX && cntO != cntX) return 0;
    return 1;
}