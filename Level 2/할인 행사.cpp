// https://school.programmers.co.kr/learn/courses/30/lessons/131127
#include <string>
#include <vector>

using namespace std;

vector<string> ww;
vector<int> nn;
int arr[10];

void    check(string &str, int a) {
    for (int i = 0; i < ww.size(); i++) {
        if (str == ww[i]) {
            arr[i] += a;
            break;
        }
    }
}

bool ft() {
    for (int i = 0; i < nn.size(); i++) {
        if (nn[i] != arr[i]) return false;
    }
    return true;
}  

int solution(vector<string> w, vector<int> n, vector<string> d) {
    int answer = 0;
    ww = w;
    nn = n;
    for (int i = 0; i < d.size(); i++) {
        if (i > 9) check(d[i - 10], -1);
        check(d[i], 1);
        if (i >= 9 && ft()) answer++;
    }
    return answer;
}