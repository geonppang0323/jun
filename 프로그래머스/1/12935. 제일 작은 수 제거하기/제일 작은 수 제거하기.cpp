#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    if (arr.size() == 1) return {-1};

    int minValue = *min_element(arr.begin(), arr.end());

    arr.erase(remove(arr.begin(), arr.end(), minValue), arr.end());

    return arr;
}

int main() {
    vector<int> arr1 = {4, 3, 2, 1};
    vector<int> arr2 = {10};

    vector<int> result1 = solution(arr1);
    vector<int> result2 = solution(arr2);

    cout << "[";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i != result1.size() - 1) cout << ",";
    }
    cout << "]" << endl; 

    cout << "[";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i != result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}