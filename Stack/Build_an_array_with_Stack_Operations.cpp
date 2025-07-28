//1441. Build an Array With Stack Operations
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int k = 1;  // Current number from 1 to n
        int i = 0;  // Index for target
        vector<string> ans;

        while (i < target.size()) {
            if (target[i] == k) {
                ans.push_back("Push");
                i++;
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            k++;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> target = {1, 3};
    int n = 3;

    vector<string> result = sol.buildArray(target, n);

    cout << "Operations: ";
    for (string& op : result) {
        cout << op << " ";
    }
    cout << endl;

    return 0;
}
