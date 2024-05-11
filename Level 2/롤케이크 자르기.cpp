// https://school.programmers.co.kr/learn/courses/30/lessons/132265?language=cpp
#include <string>
#include <vector>

using namespace std;
int at[10001], bt[10001], acnt, bcnt, answer;;


int solution(vector<int> topping) {
    for (int i = 0; i < topping.size(); i++) {
        if (!at[topping[i]]) acnt++;
        at[topping[i]]++;
    }
    for (int i = 0; i < topping.size(); i++) {
        if (!bt[topping[i]]) bcnt++;
        bt[topping[i]]++;
        at[topping[i]]--;
        if (!at[topping[i]]) acnt--;
        if (acnt == bcnt) answer++;
        if (bcnt > acnt) break;
    }
    return answer;
}