// https://school.programmers.co.kr/learn/courses/30/lessons/12911
#include <string>
#include <vector>
#include <bitset>
using namespace std;

bool check(int n, int s) {
    bitset<8> a(n);
    bitset<8> b(s);
    int acnt = 0, bcnt = 0;
    for (int i = 0; i < 8; i++) {
        if (a[i] == 1) acnt++;
        if (b[i] == 1) bcnt++;
    }
    if (acnt == bcnt) return true;
    else return false;
}

int solution(int n) {
    int s = n + 1;
    while (true) {
        if (check(n, s)) return s;
        s++;
    }
}