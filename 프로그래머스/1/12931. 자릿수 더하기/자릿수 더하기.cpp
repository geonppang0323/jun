#include <iostream>
using namespace std;

int solution(int N) {
    int sum = 0;
    
    while (N > 0) {
        sum += N % 10; // 1의 자리 더하기
        N /= 10;       // 1의 자리 제거
    }
    
    return sum;
}

int main() {
    cout << solution(123) << endl; // 출력: 6
    cout << solution(987) << endl; // 출력: 24
    return 0;
}
