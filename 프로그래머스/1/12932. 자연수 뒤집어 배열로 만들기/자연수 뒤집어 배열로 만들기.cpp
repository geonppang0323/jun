#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(long long n) {
    vector<int> result;

    while (n > 0) {
        result.push_back(n % 10);  
        n /= 10;                   
    }

    return result;
}
int main() {
    long long n;
    cout << "자연수 n을 입력하세요 (최대 10조): ";
    cin >> n;

    vector<int> answer = solution(n);

    cout << "결과: [ ";
    for (int digit : answer) {
        cout << digit << " ";
    }
    cout << "]" << endl;

    return 0;
}
