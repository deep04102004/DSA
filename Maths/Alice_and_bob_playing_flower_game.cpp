//3021. Alice and Bob Playing Flower Game
#include <iostream>
using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {
        // Alice wins when total flowers (x+y) is odd
        // Exactly half the pairs (x,y) have odd sum
        return (long long)n * m / 2;
    }
};

int main() {
    Solution sol;

    // Example test case
    int n = 3, m = 2;
    cout << sol.flowerGame(n, m) << endl;  // Output: 3

    // You can try more cases
    cout << sol.flowerGame(5, 5) << endl;  // Output: 12
    cout << sol.flowerGame(4, 7) << endl;  // Output: 14

    return 0;
}
