// https://school.programmers.co.kr/learn/courses/30/lessons/12923
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for (int i = begin; i <= end; i++) {
        if (i == 1)  answer.push_back(0);
        else {
            int a = 1;
            for (int j = 2; j * j <= i; j++)
                if (i % j == 0) {
                    a = j;
                    if (i / j <= 10000000) {
                        a = i / j;
                        break;
                    }
                }
            answer.push_back(a);
        }
    }
    return answer;
}