#include <iostream>
using namespace std;

long long solution(int a, int b) {
    long long start = min(a, b);
    long long end = max(a, b);

    long long n = end - start + 1;
    long long result = n * (start + end) / 2;

    return result;
}

int main() {
    cout << solution(3, 5) << endl;  
    cout << solution(3, 3) << endl;
    cout << solution(5, 3) << endl;  
    return 0;
}
