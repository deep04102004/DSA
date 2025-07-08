//1394. Find Lucky Integer in an Array
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;

        int ans = 0;

        for (int& a : arr) mp[a]++;

        for (auto& b : mp) {
            if (b.first == b.second) {
                ans = max(ans, b.first);
            }
        }

        return ans > 0 ? ans : -1;
    }
};

int main() {
    Solution sol;
    
    vector<int> arr = {2,2,3,3,3,4,4,4,4,5};
    
    int result = sol.findLucky(arr);

    cout << "Lucky number: " << result << endl; //output:4
    
    return 0;
}
