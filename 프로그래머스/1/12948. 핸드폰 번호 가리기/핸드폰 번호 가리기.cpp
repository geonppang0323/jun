#include <iostream>
#include <string>

using namespace std;

string solution(string phone_number) {
    int len = phone_number.length();
    for (int i = 0; i < len - 4; i++) {
        phone_number[i] = '*';
    }
    return phone_number;
}

int main() {
    cout << solution("01033334444") << endl;
    cout << solution("027778888") << endl;
    return 0;
}