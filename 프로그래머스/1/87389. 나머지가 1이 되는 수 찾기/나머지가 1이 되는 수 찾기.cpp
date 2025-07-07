#include <iostream>
using namespace std;

int solution(int n) {
    for (int x = 1; x < n; ++x) {
        if (n % x == 1) {
            return x;
        }
    }

    return -1;
}
int main() {
    int n;
    cout << "자연수 n을 입력하세요 (3 이상 1,000,000 이하): ";
    cin >> n;

    cout << "n % x == 1을 만족하는 가장 작은 x는: " << solution(n) << endl;

    return 0;
}
