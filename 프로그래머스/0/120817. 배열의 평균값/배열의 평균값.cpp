#include <iostream>
#include <vector>
using namespace std;

double solution(vector<int> numbers) {
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    return static_cast<double>(sum) / numbers.size();
}

int main() {
    vector<int> numbers = {89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
    cout << solution(numbers) << endl;
    return 0;
}

