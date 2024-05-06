// https://school.programmers.co.kr/learn/courses/30/lessons/12905
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> board)
{
    int n = board.size();
    int m = board[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!board[i][j]) continue;
            if (i && j) board[i][j] = min(board[i][j - 1], min(board[i - 1][j - 1], board[i - 1][j])) + 1;
            if (board[i][j] > ans) ans = board[i][j];
        }
    }
    return ans * ans;
}