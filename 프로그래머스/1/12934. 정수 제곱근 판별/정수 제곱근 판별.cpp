#include <iostream>
#include <cmath> // sqrt 사용
using namespace std;

long long solution(long long n) {
    long long root = sqrt(n); 

    if (root * root == n) {
        return (root + 1) * (root + 1);
    } else {
        return -1;
    }
}

int main() {
    long long n;
    cout << "양의 정수 n 입력 (최대 50조): ";
    cin >> n;

    long long result = solution(n);
    cout << "결과: " << result << endl;

    return 0;
}
