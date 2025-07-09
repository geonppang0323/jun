#include <iostream>
#include <string>
using namespace std;

int solution(string s) {
    return stoi(s);
}

int main() {
    string s;
    cout << "문자열 s 입력 (예: \"1234\", \"-567\"): ";
    cin >> s;

    int result = solution(s);
    cout << "변환된 정수: " << result << endl;

    return 0;
}
