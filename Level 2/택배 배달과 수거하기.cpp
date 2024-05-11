// https://school.programmers.co.kr/learn/courses/30/lessons/150369
#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> d, vector<int> p) {
    long long answer = 0;
    int d_idx = -1, p_idx = -1;
    for (int i = 0; i < d.size(); i++) {
        if (d[i]) d_idx = i;
        if (p[i]) p_idx = i;
    }
    while (p_idx >= 0 || d_idx >= 0) {
        int idx = max(d_idx, p_idx);
        int c = cap;
        for (int i = d_idx; i >= 0; i--) {
            if (c >= d[i]) {c -= d[i]; d[i] = 0;}
            else {d[i] -= c; d_idx = i; break;}
            if (i == 0) d_idx = -1;
        }
        c = cap;
        for (int i = p_idx; i >= 0; i--) {
            if (c >= p[i]) {c -= p[i]; p[i] = 0;}
            else {p[i] -= c; p_idx = i; break;}
            if (i == 0) p_idx = -1;
        }
        answer += (idx + 1) * 2;
    }
    return answer;
}