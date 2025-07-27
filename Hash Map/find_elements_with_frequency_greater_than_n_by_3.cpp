//229. Majority Element II
#include <iostream>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();

    map<int,int> mp; // ordered map to keep keys sorted
    for (int &a : nums) {
        mp[a]++; // count frequencies
    }

    vector<int> ans;
    for (auto &b : mp) {
        if (b.second > floor(n / 3)) {
            ans.push_back(b.first);
        }
    }
    return ans;
}

int main() {
    // Example input
    vector<int> nums = {2, 2, 3, 1, 3, 2, 1, 1};

    vector<int> res = majorityElement(nums);

    // Print result
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
