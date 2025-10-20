#include <iostream>
#include <string>

using namespace std;

string solution(string s) {
    int len = s.length();
    int mid = len / 2;

    if (len % 2 == 1) {
        return string(1, s[mid]);
    }

    else {
        return s.substr(mid - 1, 2);
    }
}

int main() {
    cout << solution("abcde") << endl; // c
    cout << solution("qwer") << endl;  // we
    return 0;
}
