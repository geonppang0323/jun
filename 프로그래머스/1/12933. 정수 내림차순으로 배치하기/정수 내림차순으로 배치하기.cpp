#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    string str = to_string(n);

    sort(str.begin(), str.end(), greater<char>());

    return stoll(str);
}

int main() {
    long long n;
    cout << "정수 n 입력 (최대 80억): ";
    cin >> n;

    long long result = solution(n);
    cout << "결과: " << result << endl;

    return 0;
}
