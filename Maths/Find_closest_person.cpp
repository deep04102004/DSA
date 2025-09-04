//3516. Find Closest Person
#include <iostream>
using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        if (abs(x - z) < abs(y - z)) {
            return 1;  // x is closer
        } 
        else if (abs(x - z) > abs(y - z)) {
            return 2;  // y is closer
        }
        else {
            return 0;  // both are equally close
        }
    }
};

int main() {
    Solution sol;

    int x = 5, y = 10, z = 7;
    int result = sol.findClosest(x, y, z);

    if (result == 1) {
        cout << "x is closer to z" << endl;
    } 
    else if (result == 2) {
        cout << "y is closer to z" << endl;
    } 
    else {
        cout << "Both are equally close to z" << endl;
    }

    return 0;
}
