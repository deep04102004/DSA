//374. Guess Number Higher or Lower
#include <iostream>
using namespace std;

// Mock picked number for testing
int pickedNumber = 42;

// Mock implementation of the guess API
int guess(int num) {
    if (num > pickedNumber) return -1;
    else if (num < pickedNumber) return 1;
    else return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        int s = 1, l = n;
        while (s <= l) {
            int mid = s + (l - s) / 2;
            int g = guess(mid);
            if (g == 0) return mid;
            else if (g == -1) l = mid - 1;
            else s = mid + 1;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int n = 100; // range [1, n]
    cout << "Guessed Number: " << sol.guessNumber(n) << endl;
    return 0;
}
