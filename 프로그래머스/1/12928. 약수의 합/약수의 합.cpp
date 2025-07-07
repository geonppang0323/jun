#include <iostream>
using namespace std;

int solution(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}
int main() {
    int n;
    cout << "정수를 입력하세요: ";
    cin >> n;

    cout << "약수의 합: " << solution(n) << endl;

    return 0;
}
