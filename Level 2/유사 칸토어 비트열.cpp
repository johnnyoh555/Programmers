// https://school.programmers.co.kr/learn/courses/30/lessons/148652
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
long d, ll, rr, cnt;

void    ft(int dep, long idx, string str) {
    long a = pow(5, d - dep);
    for (int i = 0; i < str.size(); i++) {
        if (idx + a * (i + 1) - 1 <= rr && idx + a * i >= ll && str[i] == '1') cnt += pow(4, d - dep);
        else if ((idx + a * i <= ll && idx + a * (i + 1) > ll) && str[i] == '1') ft(dep + 1, idx + i * a, "11011");
        else if ((idx + a * i <= rr && idx + a * (i + 1) > rr) && str[i] == '1') ft(dep + 1, idx + i * a, "11011");
    }
}

int solution(int n, long long l, long long r) {
    d = n;
    ll = l - 1;
    rr = r - 1;
    ft(1, 0, "11011");
    return cnt;
}