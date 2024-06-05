// https://school.programmers.co.kr/learn/courses/30/lessons/12980
#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    while (n) {
        if (n % 2 == 0) n /= 2;
        else {n -= 1; ans++;}
    }
    return ans;
}