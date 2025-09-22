#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int sum = 0;
    for (size_t i = 0; i < absolutes.size(); i++) {
        if (signs[i])
            sum += absolutes[i];
        else
            sum -= absolutes[i];
    }
    return sum;
}

int main() {
    vector<int> absolutes1 = {4, 7, 12};
    vector<bool> signs1 = {true, false, true};
    cout << solution(absolutes1, signs1) << endl; 

    vector<int> absolutes2 = {1, 2, 3};
    vector<bool> signs2 = {false, false, true};
    cout << solution(absolutes2, signs2) << endl;

    return 0;
}
