//342. Power of Four
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 0) {
            return false;
        }

        while (n % 4 == 0) {  // keep dividing by 4
            n /= 4;
        }

        return n == 1;  // true if reduced to 1
    }
};

int main() {
    Solution sol;

    int n = 64;  // test input
    if (sol.isPowerOfFour(n)) {
        cout << n << " is a power of 4" << endl;
    } else {
        cout << n << " is NOT a power of 4" << endl;
    }

    return 0;
}
