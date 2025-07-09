//1865. Finding Pairs With a Certain Sum
#include <bits/stdc++.h>
using namespace std;

class FindSumPairs {
private:
    vector<int> n1, n2;
    unordered_map<int, int> mp; // frequency map for nums2

public:
    // Constructor
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (int a : n2) {
            mp[a]++;
        }
    }

    // Add val to nums2[index]
    void add(int index, int val) {
        mp[n2[index]]--;           // reduce old value count
        n2[index] += val;          // update value
        mp[n2[index]]++;           // increase new value count
    }

    // Count number of (i, j) such that nums1[i] + nums2[j] == tot
    int count(int tot) {
        int cnt = 0;
        for (int b : n1) {
            cnt += mp[tot - b];
        }
        return cnt;
    }
};

int main() {
    vector<int> nums1 = {1, 1, 2, 2, 2, 3};
    vector<int> nums2 = {1, 4, 5, 2, 5, 4};

    FindSumPairs* obj = new FindSumPairs(nums1, nums2);

    cout << obj->count(7) << endl; // Output: 8
    obj->add(3, 2);                // nums2[3] = 2 + 2 = 4
    cout << obj->count(8) << endl; // Output: 2
    cout << obj->count(4) << endl; // Output: 1
    obj->add(0, 1);                // nums2[0] = 1 + 1 = 2
    obj->add(1, 1);                // nums2[1] = 4 + 1 = 5
    cout << obj->count(7) << endl; // Output: 11

    delete obj;
    return 0;
}
