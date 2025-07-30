//Subarrays with sum K (GFG).
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int cntSubarrays(vector<int> &arr, int k) {
    int n = arr.size();
    int count = 0, sum = 0;

    unordered_map<int, int> prefixfreq;
    prefixfreq[0] = 1;  // To handle subarrays starting from index 0

    for (int a : arr) {
        sum += a;

        if (prefixfreq.find(sum - k) != prefixfreq.end()) {
            count += prefixfreq[sum - k];
        }

        prefixfreq[sum]++;
    }

    return count;
}

int main() {
    vector<int> arr = {1, 2, 3};
    int k = 3;

    cout << "Number of subarrays with sum " << k << " = " << cntSubarrays(arr, k) << endl;

    return 0;
}
