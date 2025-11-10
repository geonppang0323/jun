#include <string>
#include <vector>
using namespace std;

long long solution(int price, int money, int count) {
    long long p = price;        
    long long c = count;        
    long long total = p * c * (c + 1) / 2;
    long long lack = total - (long long)money;
    return lack > 0 ? lack : 0;
}


