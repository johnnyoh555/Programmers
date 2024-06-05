// https://school.programmers.co.kr/learn/courses/30/lessons/84512
#include <string>
#include <vector>
using namespace std;
string w;
bool flag;
int cnt, ans;
char arr[5] = {'A', 'E', 'I', 'O', 'U'};

void ft(int s, string str) {
    if (str == w) ans = cnt;
    if (s == 5) return;
    for (int i = 0; i < 5; i++) {cnt++; ft(s + 1, str + arr[i]);}
}

int solution(string word) {
    w = word;
    ft(0, "");
    return ans;
}