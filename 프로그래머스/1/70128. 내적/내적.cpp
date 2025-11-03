#include <vector>
using namespace std;

int solution(vector<int> a, vector<int> b) {
    int result = 0;
    for (size_t i = 0; i < a.size(); i++) {
        result += a[i] * b[i];
    }
    return result;
}
