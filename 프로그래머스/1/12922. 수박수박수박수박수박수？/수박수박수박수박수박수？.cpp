#include <string>
using namespace std;

string solution(int n) {
    string pattern = "수박";
    string result = "";

    for (int i = 0; i < n / 2; i++) {
        result += pattern;
    }

    if (n % 2 == 1)
        result += "수";

    return result;
}
