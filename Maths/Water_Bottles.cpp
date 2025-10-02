//1518. Water Bottles
#include <iostream>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = numBottles;
        int rem = 0;
        int emptyBottles = numBottles + rem;

        while (emptyBottles >= numExchange) {
            numBottles = emptyBottles / numExchange;   // new bottles obtained
            rem = emptyBottles % numExchange;          // remaining bottles
            emptyBottles = numBottles + rem;           // update empty bottles
            sum += numBottles;                         // add drunk bottles
        }
        return sum;
    }
};

int main() {
    Solution sol;

    int numBottles = 15, numExchange = 4;
    cout << "Total bottles you can drink: " 
         << sol.numWaterBottles(numBottles, numExchange) << endl;

    return 0;
}
