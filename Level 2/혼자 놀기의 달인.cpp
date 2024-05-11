// https://school.programmers.co.kr/learn/courses/30/lessons/131130
#include <string>
#include <vector>

using namespace std;
int open[101], f, s;

int solution(vector<int> cards) {
    for (int i = 0; i < cards.size(); i++) {
        int idx = i + 1;
        if (open[idx]) continue;
        int cnt = 0;
        while (true) {
            if (open[idx]) break;       
            open[idx] = 1;
            cnt++;
            idx = cards[idx - 1];
        }
        if (cnt > f) {s = f; f = cnt;}
        else if (cnt > s) s = cnt;
    }
    return f * s;
}