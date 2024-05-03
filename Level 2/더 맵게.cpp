// https://school.programmers.co.kr/learn/courses/30/lessons/42626
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<long, vector<long>, greater<long>> pq(scoville.begin(), scoville.end());
    while (pq.size() > 1 && pq.top() < K) {
        long a = pq.top(); pq.pop();
        long b = pq.top(); pq.pop();
        pq.push(a + b * 2);
        answer++;
    }
    if (pq.top() < K) answer = -1;
    return answer;
}