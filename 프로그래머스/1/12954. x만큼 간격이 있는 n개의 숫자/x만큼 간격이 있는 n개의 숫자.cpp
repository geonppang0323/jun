#include <iostream>
#include <vector>
using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> result;
    for (int i = 1; i <= n; ++i) {
        result.push_back((long long)x * i);
    }
    return result;
}

// 테스트용 main 함수
int main() {
    int x, n;
    cout << "정수 x 입력: ";
    cin >> x;
    cout << "자연수 n 입력: ";
    cin >> n;

    vector<long long> answer = solution(x, n);
    cout << "결과: [ ";
    for (long long num : answer) {
        cout << num << " ";
    }
    cout << "]" << endl;

    return 0;
}
