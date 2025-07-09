#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(long long n) {
    vector<int> result;

    // n의 각 자릿수를 뒤에서부터 추출해 벡터에 저장
    while (n > 0) {
        result.push_back(n % 10);  // 마지막 자릿수
        n /= 10;                   // 자릿수 하나 줄이기
    }

    return result;
}

// 테스트용 main 함수
int main() {
    long long n;
    cout << "자연수 n 입력 (최대 10조): ";
    cin >> n;

    vector<int> answer = solution(n);

    cout << "결과: [ ";
    for (int digit : answer) {
        cout << digit << " ";
    }
    cout << "]" << endl;

    return 0;
}

