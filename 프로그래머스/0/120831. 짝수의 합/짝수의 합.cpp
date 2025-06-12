#include <iostream>
using namespace std;

int solution(int n) {
    int sum = 0;
    for (int i = 2; i <= n; i += 2) {
        sum += i;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    cout << solution(n) << endl;
    return 0;
}
