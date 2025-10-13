#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int total = 0;
    // 0부터 9까지 합은 45
    int sum = 45;

    for (int n : numbers) {
        sum -= n;
    }
    return sum;
}

int main() {
    vector<int> numbers1 = {1, 2, 3, 4, 6, 7, 8, 0};
    vector<int> numbers2 = {5, 8, 4, 0, 6, 7, 9};

    cout << solution(numbers1) << endl; // 14
    cout << solution(numbers2) << endl; // 6

    return 0;
}