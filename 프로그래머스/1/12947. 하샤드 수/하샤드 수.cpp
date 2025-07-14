#include <iostream>

using namespace std;

bool solution(int x) {
    int original = x;
    int digitSum = 0;

    while (x > 0) {
        digitSum += x % 10;
        x /= 10;
    }
    return (original % digitSum == 0);
}

int main() {

    int testCases[] = {10, 12, 11, 13};
    
    for (int x : testCases) {
        cout << "x = " << x << " -> " << (solution(x) ? "true" : "false") << endl;
    }

    return 0;
}
